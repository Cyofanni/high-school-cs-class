def rotate_l(w):
    return w[1:len(w)] + w[0]

def rotations_sorted(w):
    rotations = [w]
    for i in range(1, len(w)):
        rotations.append(rotate_l(rotations[i - 1]))
    return sorted(rotations)

def bwt(w):
    rotations = rotations_sorted(w)
    bwt_str = str()
    for rot in rotations:
        bwt_str += rot[len(rot) - 1]

    counts = dict()
    for rot in rotations:
        counts[rot[0]] = 0
    for rot in rotations:
        counts[rot[0]] += 1

    counts_list = list(counts.items())
    for i in range(1, len(counts_list)):
        counts_list[i] = counts_list[i][0], counts_list[i - 1][1] + counts_list[i][1]

    for item in counts_list:
        counts[item[0]] = item[1]

    rank = [-1 for _ in range(len(w))]
    for i in range(len(rank) - 1, -1, -1):
        rank[i] = counts[bwt_str[i]] - 1
        counts[bwt_str[i]] -= 1

    return bwt_str, rank

data = 'rutabaga$'
print(rotations_sorted(data))
print(bwt(data))
