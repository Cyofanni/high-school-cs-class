def knapsack_fract(items, max_weight):
    items.sort(key = lambda x: x[0] / x[1])
    print(items)
    knapsack = []

    i = len(items) - 1
    weight = 0
    while i >= 0 and weight < max_weight:
        if items[i][1] < max_weight - weight:
            knapsack.append(items[i])
            weight += items[i][1]
        else:
            k = (max_weight - weight) / items[i][1]
            knapsack.append((k * items[i][0], k * items[i][1]))
            weight += k * items[i][1]
        i -= 1

    return knapsack

#(value, weight)
items = [(6,3),(2,6),(30,3),(30,15),(40,30),(20,15)]
res = knapsack_fract(items, 20)
print(res)
