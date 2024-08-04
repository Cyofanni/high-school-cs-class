import math

def knapsack_int(items, i, weight):
    if weight <= 0 or i == len(items):
        return 0

    res = -math.inf
    for k in range(i, len(items)):
        if items[k][1] <= weight:
            new_weight = weight - items[k][1]
            v1 = items[k][0] + knapsack_int(items, k + 1, new_weight)
        else:
            v1 = -math.inf
        v2 = knapsack_int(items, k + 1, weight)
        v3 = max(v1, v2)
        if v3 > res:
            res = v3

    return res

#(value, weight)
items = [(60,10),(100,20),(120,30)]
res = knapsack_int(items, 0, 50)
print(res)
print()

items = [(1,4),(2,5),(3,1)]
res = knapsack_int(items, 0, 1)
print(res)
print()
