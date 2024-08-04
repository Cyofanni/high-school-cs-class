import math

def knapsack_int(items, i, weight):
    if weight <= 0 or i == len(items):
        return 0

    if items[i][1] <= weight:
        new_weight = weight - items[i][1]
        v1 = items[i][0] + knapsack_int(items, i + 1, new_weight)
    else:
        v1 = -math.inf
    v2 = knapsack_int(items, i + 1, weight)

    if v1 >= v2:
        return v1
    return v2

#(value, weight)
items = [(60,10),(100,20),(120,30)]
res = knapsack_int(items, 0, 80)
print(res)
print()

items = [(1,4),(2,5),(3,6)]
res = knapsack_int(items, 0, 3)
print(res)
print()
