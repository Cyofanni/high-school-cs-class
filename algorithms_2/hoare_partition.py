import random

def hoare_partition(arr, low, high):
    pivot = arr[low]
    i = low - 1
    j = high + 1
    while True:
        while True:
            i += 1
            if arr[i] >= pivot:
                break
        while True:
            j -= 1
            if arr[j] <= pivot:
                break
        if i >= j:
            return j
        arr[i], arr[j] = arr[j], arr[i]

def quicksort(arr, low, high):
    if low >= high:
        return
    q = hoare_partition(arr, low, high)
    quicksort(arr, low, q)
    quicksort(arr, q + 1, high)

ls = [random.randint(0, 1000) for _ in range(1000)]
ls_cp = ls.copy()
quicksort(ls, 0, len(ls) - 1)
print(ls == sorted(ls_cp))
