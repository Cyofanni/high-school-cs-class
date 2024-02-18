import math, random

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

def merge_sort_iterative(A):
  n = len(A)
  h = math.log2(n)
  if h != int(h):
    return

  step = 2
  i = 1
  while i <= h:
    j = 0
    while j <= n - step:
      l, h = j, j + step - 1
      m = (l + h) // 2
      merge(A, j, m, j + step - 1)
      j += step
    i += 1
    step *= 2

a = [random.randint(0, 2 ** 12) for _ in range(2 ** 12)]
a_cp = a.copy()
merge_sort_iterative(a)
print(a == sorted(a_cp))
