import random

def left(i):
    return 2 * i

def right(i):
    return 2 * i + 1

def max_heapify(A, size, i):
    if i > size // 2:
        return
    l = left(i)
    r = right(i)
    largest = A[i]
    largest_index = i
    if A[l] > largest:
        largest = A[l]
        largest_index = l
    if r <= size and A[r] > largest:
        largest = A[r]
        largest_index = r
    if largest_index != i:
        t = A[i]
        A[i] = A[largest_index]
        A[largest_index] = t
        max_heapify(A, size, largest_index)
    else:
        return

def build_max_heap(A, size):
    for i in range(size // 2, 0, -1):
        max_heapify(A, size, i)

def heap_sort(A, size):
    build_max_heap(A, size)
    heap_size = size
    for i in range(size - 1):
        t = A[heap_size]
        A[heap_size] = A[1]
        A[1] = t
        heap_size -= 1
        max_heapify(A, heap_size, 1)

ar_size = 100000
A = [random.randint(0, 10000) for i in range(ar_size)]
A_1 = A.copy()
A_sorted = sorted(A)

A_1.insert(0, None)
heap_sort(A_1, ar_size)
print(A_1)
print(sorted(A) == A_1[1:])
