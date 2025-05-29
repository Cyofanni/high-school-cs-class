import math, random, time

def knapsack_int(items, i, weight):
    if weight <= 0 or i == len(items):
        return 0
    if items[i][1] > weight:
        return knapsack_int(items, i + 1, weight)
    new_weight = weight - items[i][1]
    v0 = items[i][0] + knapsack_int(items, i + 1, new_weight)
    v1 = knapsack_int(items, i + 1, weight)
    return max(v0, v1)

def knapsack_int_1(items, i, weight):
    if weight <= 0 or i == -1:
        return 0
    if items[i][1] > weight:
        return knapsack_int_1(items, i - 1, weight)
    new_weight = weight - items[i][1]
    v0 = items[i][0] + knapsack_int_1(items, i - 1, new_weight)
    v1 = knapsack_int_1(items, i - 1, weight)
    return max(v0, v1)

lookup = {}
def knapsack_int_memoized(items, i, weight):
    if weight <= 0 or i == -1:
        return 0
    if items[i][1] > weight:
        if (i - 1, weight) in lookup.keys():
            return lookup[(i - 1, weight)]
        res = knapsack_int_memoized(items, i - 1, weight)
        lookup[(i - 1, weight)] = res
        return res
    if (i, weight) in lookup.keys():
        return lookup[(i, weight)]
    new_weight = weight - items[i][1]
    v0 = items[i][0] + knapsack_int_memoized(items, i - 1, new_weight)
    v1 = knapsack_int_memoized(items, i - 1, weight)
    res = max(v0, v1)
    lookup[(i, weight)] = res
    return res

def knapsack_int_bottom_up(items, weight):
    n = len(items)
    items_1 = [None] + items    #index from 1
    print(items_1)
    dp = [[0] * (weight + 1) for _ in range(n + 1)]
    print(dp)
    for i in range(1, n + 1):    #loop on items
        for j in range(1, weight + 1):    #loop on possible available weights
            if items_1[i][1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                v0 = items_1[i][0] + dp[i - 1][j - items_1[i][1]]
                v1 = dp[i - 1][j]
                dp[i][j] = max(v0, v1)
    print('####')
    for row in dp:
        print(row)
    print('####')

#(value, weight)
items = [(random.randint(1,100),random.randint(1,100)) for _ in range(5)]
print(items)
print('total value: ', end = '')
print(sum(item[0] for item in items))
W = 10000
start = time.time()
res0 = knapsack_int_memoized(items, len(items) - 1, W)
end = time.time()
print(res0)
print('time: ', end - start)
start = time.time()
res1 = knapsack_int(items, 0, W)
end = time.time()
print(res1)
print('time: ', end - start)

items = [(5,4),(4,3),(3,2),(2,1)]
W = 6
knapsack_int_bottom_up(items, W)
