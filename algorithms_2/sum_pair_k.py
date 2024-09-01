import math, random, time

def bin_search(arr, l, h, key):
    if l > h:
        return False
    m = (l + h) // 2
    if key == arr[m]:
        return True
    if key < arr[m]:
        return bin_search(arr, l, m - 1, key)
    return bin_search(arr, m + 1, h, key)

def merge(lst, l, m, h):
    left = lst[l:m + 1]
    right = lst[m + 1:h + 1]
    left.append(math.inf)
    right.append(math.inf)

    left_index = 0
    right_index = 0
    for i in range(l, h + 1):
        if left[left_index] <= right[right_index]:
            lst[i] = left[left_index]
            left_index += 1
        else:
            lst[i] = right[right_index]
            right_index += 1

def merge_sort(lst, l, h):
    if l < h:
        m = (l + h) // 2
        merge_sort(lst, l, m)
        merge_sort(lst, m + 1, h)
        merge(lst, l, m, h)

#assume only positive keys
def sum_pair_k(arr, k):
    sz = len(arr)
    #merge_sort(arr, 0, sz - 1)
    arr.sort()
    i = 1
    while i < sz and arr[i] < k:
        diff = k - arr[i]
        search_res = bin_search(arr, 0, i - 1, diff)
        if search_res:
            return True
        i += 1

    return False

def sum_pair_k_naive(arr, k):
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == k:
                return (i, j, arr[i], arr[j])

    return False

ls = [random.randint(0, 100000) for _ in range(10000000)]
ls_cp = ls.copy()

s_time = time.time()
print(sum_pair_k(ls, 1520))
e_time = time.time()
print(e_time - s_time)

print()
s_time = time.time()
print(sum_pair_k_naive(ls_cp, 1520))
e_time = time.time()
print(e_time - s_time)
