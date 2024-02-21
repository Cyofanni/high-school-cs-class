import random

def sum_dq(A, l, h):
  if l > h:
    return 0
  m = (l + h) // 2
  return A[m] + sum_dq(A, l, m - 1) + sum_dq(A, m + 1, h)

n = 1000000
a = [random.randint(0, n) for _ in range(n)]
print(sum_dq(a, 0, len(a) - 1) == sum(a))
