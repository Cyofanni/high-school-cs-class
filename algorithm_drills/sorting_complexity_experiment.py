import math, random, time

#good example: v1 = [random.randint(0, 3000) for i in range(50000)]
size = 100000
range_upper_limit = 6000
v1 = [random.randint(0, range_upper_limit) for i in range(size)]
v2 = v1.copy()
v3 = v2.copy()
v4 = v3.copy()
v5 = v4.copy()
v6 = v5.copy()
v7 = v6.copy()

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

start_time = time.time()
print('#merge sort')
merge_sort(v7, 0, size - 1)
end_time = time.time()
print('sorted:', sorted(v7) == v7)
print('merge sort time:', end_time - start_time)
print()

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

def quick_sort(A, low, high):
    if low >= high:
        return
    pivot_index = partition(A, low, high)
    quick_sort(A, low, pivot_index - 1)
    quick_sort(A, pivot_index + 1, high)

start_time = time.time()
print('#quicksort')
quick_sort(v6, 0, size - 1)
end_time = time.time()
print('sorted:', sorted(v6) == v6)
print('quicksort time:', end_time - start_time)

def counting_sort(A, k):
    B = [0 for i in range(k)]
    for i in range(len(A)):
        B[A[i]] = B[A[i]] + 1

    for i in range(1, len(B)):
        B[i] = B[i] + B[i - 1]

    C = [0 for i in range(len(A))]

    for i in range(len(A)):
        sorted_index = B[A[i]] - 1
        C[sorted_index] = A[i]
        B[A[i]] = B[A[i]] - 1

    return C

start_time = time.time()
print()
print('#counting sort')
v5_counting_sorted = counting_sort(v5, range_upper_limit + 1)
end_time = time.time()
print('sorted:', sorted(v5) == v5_counting_sorted)
print('counting sort time:', end_time - start_time)

print()
start_time = time.time()
print('#heapsort')

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

v4_1 = v4.copy()
v4_1.insert(0, None)
heap_sort(v4_1, size)

end_time = time.time()
print('sorted:', sorted(v4) == v4_1[1:])
print('heapsort time:', end_time - start_time)

print()
start_time = time.time()
print('#insertion sort')
for i in range(1, len(v1)):
  item = v1[i]
  j = i - 1
  while j >= 0 and item < v1[j]:
    v1[j + 1] = v1[j]
    j -= 1
  v1[j + 1] = item
  #print(v1[1:20])

end_time = time.time()
print('sorted:', v1 == sorted(v1))
print('insertion sort time:', end_time - start_time)

print()
start_time = time.time()
print('#bubble sort')
for i in range(len(v2) - 1, 0, -1):
  for j in range(0, i):
    if v2[j] > v2[j + 1]:
      t = v2[j]
      v2[j] = v2[j + 1]
      v2[j + 1] = t
  #print(v2[1:70])

end_time = time.time()
print('sorted:', v2 == sorted(v2))
print('bubble sort time:', end_time - start_time)

print()
start_time = time.time()
print('#selection sort')
for i in range(0, len(v3) - 1):
  min = v3[i]
  pos_min = i
  for j in range(i + 1, len(v3)):
    if v3[j] < min:
      min = v3[j]
      pos_min = j
  t = v3[i]
  v3[i] = v3[pos_min]
  v3[pos_min] = t
  #print(v3[1:70])

end_time = time.time()
print('sorted:', v3 == sorted(v3))
print('selection sort time:', end_time - start_time)
