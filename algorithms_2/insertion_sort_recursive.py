import random

def insertion_sort_recursive(A, i):
  if i == len(A):
    return
  item = A[i]
  j = i - 1
  while j >= 0 and item < A[j]:
    A[j + 1] = A[j]
    j -= 1
  A[j + 1] = item
  insertion_sort_recursive(A, i + 1)

a = [random.randint(0, 100) for _ in range(500)]
a1 = a.copy()
insertion_sort_recursive(a, 0)
print(a)
print(a == sorted(a1))
