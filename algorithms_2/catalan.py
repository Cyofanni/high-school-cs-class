import sympy as sy

def catalan(n):
  return sy.factorial(2 * n) / (sy.factorial(n + 1) * sy.factorial(n))

def catalan_rec(n):
  if n == 0:
    return 1
  s = 0
  for i in range(1, n + 1):
    s += catalan_rec(i - 1) * catalan_rec(n - i)
  return s

for n in range(25):
  print(catalan(n))
  print(catalan_rec(n))
  print()
