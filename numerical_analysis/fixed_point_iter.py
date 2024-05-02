def f1(x):
  return 1 / (2 + x)

def f2(x):
  return ((-x) ** 3 + 4 * x ** 2 + 8) / 6

def fixed_point_iter(x0, f, tol, max_iters):
  for i in range(max_iters):
     x = f(x0)
     if abs(x - x0) < tol:
       break
     x0 = x
  return x

x0 = -1.5
print(fixed_point_iter(x0, f1, 0.00001, 10))

x0 = -1
print(fixed_point_iter(x0, f2, 0.0000000000001, 50))

