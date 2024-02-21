import random

def max_dq(A, p, r):
  if p == r:
    return A[p]
  if r - p == 1:
    return max(A[p], A[r])
  q = (p + r) // 2
  mx_q = A[q]
  mx_l = max_dq(A, p, q - 1)
  mx_r = max_dq(A, q + 1, r)
  res = mx_q
  if mx_l > res:
    res = mx_l
  if mx_r > res:
    res = mx_r
  return res

n = 1000
a = [random.randint(0, n) for _ in range(n)]
print(max_dq(a, 0, n - 1) == max(a))
