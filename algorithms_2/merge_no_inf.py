import random, time

#merge without +inf
def merge(A, l, m, h):
  left = A[l:m+1]
  right = A[m+1:h+1]
  sz_l, sz_r = len(left), len(right)
  li, ri = 0, 0
  for i in range(l, h + 1):
    if li < sz_l and ri < sz_r:
      if left[li] <= right[ri]:
        A[i] = left[li]
        li += 1
      else:
        A[i] = right[ri]
        ri += 1;
    elif ri == sz_r:
      A[i] = left[li]
      li += 1
    else:
      A[i] = right[ri]
      ri += 1

def merge_sort(lst, l, h):
  if l < h:
    m = (l + h) // 2
    merge_sort(lst, l, m)
    merge_sort(lst, m + 1, h)
    merge(lst, l, m, h)

size = 200000
range_upper_limit = 200000
v1 = [random.randint(0, range_upper_limit) for i in range(size)]
v2 = v1.copy()

print('#merge sort')
start_time = time.time()
merge_sort(v1, 0, size - 1)
end_time = time.time()

print('sorted:', sorted(v2) == v1)
print('merge sort time:', end_time - start_time)
print()
