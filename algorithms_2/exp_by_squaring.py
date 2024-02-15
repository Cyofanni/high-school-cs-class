def exp_by_squaring(x, n):
  if n == 0:
    return 1
  if n % 2 == 1:
    return x * exp_by_squaring(x * x, (n - 1) / 2)
  return exp_by_squaring(x * x, n / 2)

b = 17
e = 24
res1 = exp_by_squaring(b, e)
res2 = b ** e
print(res1, res2)
print(res1 == res2)
