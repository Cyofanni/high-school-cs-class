import random

def hoare_partition(A, l, h):
    pivot = A[l]
    i = l + 1
    j = h
    while True:
        while i <= j and A[i] <= pivot:
            i += 1
        while i <= j and A[j] >= pivot:
            j -= 1
        if i <= j:
            A[i], A[j] = A[j], A[i]
        else:
            break
    A[l], A[j] = A[j], A[l]
    return j

def quicksort(A, l, h):
    if l > h:
        return
    q = hoare_partition(A, l, h)
    quicksort(A, l, q - 1)
    quicksort(A, q + 1, h)

sz = 30000
a = [random.randint(0, sz) for _ in range(sz)]
a_cp = a.copy()
quicksort(a, 0, len(a) - 1)
print(a == sorted(a_cp))
