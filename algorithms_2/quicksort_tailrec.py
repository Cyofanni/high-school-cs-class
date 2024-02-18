import random

def partition(A, low, high):
    i = low - 1
    pivot = A[high]
    for j in range(low, high + 1):
        if A[j] <= pivot:
            i = i + 1
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
    return i

def quicksort_tailrec(A, l, h):
  while l < h:
    p = partition(A, l, h)
    quicksort_tailrec(A, l, p - 1)
    l = p + 1

a = [random.randint(0, 3000) for _ in range(200)]
a_cp = a.copy()
quicksort_tailrec(a, 0, len(a) - 1)
print(a)
print(a == sorted(a_cp))
