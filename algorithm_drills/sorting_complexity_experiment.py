import math, random, time

size = 15641
range_upper_limit = 15641
v1 = [random.randint(0, range_upper_limit) for i in range(size)]
v2 = v1.copy()
v3 = v2.copy()
v4 = v3.copy()
v5 = v4.copy()
v6 = v5.copy()
v7 = v6.copy()
v8 = v7.copy()

#Mergesort
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

print('#merge sort')
start_time = time.time()
merge_sort(v1, 0, size - 1)
end_time = time.time()

print('sorted:', sorted(v2) == v1)
print('merge sort time:', end_time - start_time)
print()
########

#Quicksort
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

def quicksort(A, low, high):
    if low >= high:
        return
    pivot_index = partition(A, low, high)
    quicksort(A, low, pivot_index - 1)
    quicksort(A, pivot_index + 1, high)

print('#quicksort')
start_time = time.time()
quicksort(v2, 0, size - 1)
end_time = time.time()

print('sorted:', sorted(v3) == v2)
print('quicksort time:', end_time - start_time)
print()
########

#Counting sort
def counting_sort(A, k):
    C = [0 for _ in range(k)]
    B = [0 for _ in range(len(A)) ]

    for i in range(len(A)):
        item = A[i]
        C[item] += 1

    for i in range(1, len(C)):
        C[i] = C[i] + C[i - 1]

    for i in range(len(A) - 1, -1, -1):
        item = A[i]
        lte_item = C[item]
        pos_item = lte_item - 1
        B[pos_item] = item
        C[item] -= 1

    return B

print('#counting sort')
start_time = time.time()
v3_counting_sorted = counting_sort(v3, range_upper_limit + 1)
end_time = time.time()

print('sorted:', sorted(v3) == v3_counting_sorted)
print('counting sort time:', end_time - start_time)
print()
########

#Heapsort
def left(i):
    if i != 0:
        return 2 * i
    return 1

def right(i):
    if i != 0:
        return 2 * i + 1
    return 2

def max_heapify(A, size, i):
    l = left(i)
    r = right(i)
    largest = A[i]
    largest_index = i
    if l <= size - 1 and A[l] > largest:
        largest = A[l]
        largest_index = l
    if r <= size - 1 and A[r] > largest:
        largest = A[r]
        largest_index = r
    if largest_index != i:
        t = A[i]
        A[i] = A[largest_index]
        A[largest_index] = t
        max_heapify(A, size, largest_index)

def build_max_heap(A, size):
    for i in range((size - 1) // 2, -1, -1):
        max_heapify(A, size, i)

def heap_sort(A, size):
    build_max_heap(A, size)
    for i in range(size - 1):
        t = A[size - 1]
        A[size - 1] = A[0]
        A[0] = t
        size -= 1
        max_heapify(A, size, 0)

print('#heapsort')
start_time = time.time()
heap_sort(v4, size)
end_time = time.time()

print('sorted:', sorted(v5) == v4)
print('heapsort time:', end_time - start_time)
print()
########

#Insertion sort
def insertion_sort(v):
    for i in range(1, len(v)):
        item = v[i]
        j = i - 1
        while j >= 0 and item < v[j]:
            v[j + 1] = v[j]
            j -= 1
        v[j + 1] = item

print('#insertion sort')
start_time = time.time()
insertion_sort(v5)
end_time = time.time()

print('sorted:', v5 == sorted(v6))
print('insertion sort time:', end_time - start_time)
print()
########

#Bubble sort
def bubble_sort(v):
    for i in range(len(v) - 1, 0, -1):
      for j in range(0, i):
        if v[j] > v[j + 1]:
          t = v[j]
          v[j] = v[j + 1]
          v[j + 1] = t

print('#bubble sort')
start_time = time.time()
bubble_sort(v6)
end_time = time.time()

print('sorted:', v6 == sorted(v7))
print('bubble sort time:', end_time - start_time)
print()
########

#Selection sort
def selection_sort(v):
    for i in range(0, len(v) - 1):
      min = v[i]
      pos_min = i
      for j in range(i + 1, len(v)):
        if v[j] < min:
          min = v[j]
          pos_min = j
      t = v[i]
      v[i] = v[pos_min]
      v[pos_min] = t

print('#selection sort')
start_time = time.time()
selection_sort(v7)
end_time = time.time()

print('sorted:', v7 == sorted(v8))
print('selection sort time:', end_time - start_time)
#######
