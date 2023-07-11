def max_heapify(ls, i, heap_size):
  max = ls[i]
  left_i = i * 2
  right_i = i * 2 + 1
  swap = ''
  if left_i <= heap_size and ls[left_i] > max:
    max = ls[left_i]
    swap = 'left'
  if right_i <= heap_size and ls[right_i] > max:
    max = ls[right_i]
    swap = 'right'
  if swap == 'left':
    t = ls[i]
    ls[i] = ls[left_i]
    ls[left_i] = t
    max_heapify(ls, left_i, heap_size)
  elif swap == 'right':
    t = ls[i]
    ls[i] = ls[right_i]
    ls[right_i] = t
    max_heapify(ls, right_i, heap_size)
  else:
    return

def build_max_heap(ls):
  sz = len(ls)
  heap_size = len(ls) - 1
  for i in range(sz // 2, 0, -1):
    max_heapify(ls, i, heap_size)

def heapsort(ls):
  build_max_heap(ls)
  high = len(ls) - 1
  heap_size = len(ls) - 1
  for i in range(high, 0, -1):
    t = ls[1]
    ls[1] = ls[i]
    ls[i] = t
    heap_size -= 1
    max_heapify(ls, 1, heap_size)

A = [None, 9, 8, 7, 6, 5, 4, 3, 2, 1]
heapsort(A)
print(A[1:len(A)])
