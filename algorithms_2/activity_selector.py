def activity_selector(a):
    subset = [a[0]]
    k = 1
    for i in range(1, len(a)):
        if a[i][0] >= subset[k - 1][1]:
            subset.append(a[i])
            k += 1

    return subset

activities = [(1,4),(3,5),(0,6),(5,7),(3,9),(5,9),
              (6,10),(7,11),(8,12),(2,14),(12,16)]
print(activity_selector(activities))

