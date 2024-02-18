import random

def insertion_sort_binsearch(A):
  sz = len(A)
  for i in range(1, sz):
    if A[i] < A[i - 1]:
      found = False
      l, h = 0, i - 1
      pos = -1
      while not found:
        m = (l + h) // 2
        if l > h:
          pos = l
          found = True
        if A[i] == A[m]:
          pos = m + 1
          found = True
        elif A[i] < A[m]:
          h = m - 1
        else:
          l = m + 1

      j = i
      while j > pos:
        t = A[j]
        A[j] = A[j - 1]
        A[j - 1] = t
        j -= 1

a = [random.randint(0, 20000) for _ in range(30000)]
a_cp = a.copy()
insertion_sort_binsearch(a)
print(a)
print(a == sorted(a_cp))
