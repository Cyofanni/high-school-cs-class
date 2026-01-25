import numpy as np

def f0(x):
  return np.log(x)

def f1(x):
  return np.sin(x)

def f2(x):
  return x ** 3 + x ** 2 + 4

def D(f, depth, pts, dx, i):
  if depth == 0:
    return f(pts[0])
  if depth == 1:
    return (f(pts[i+1])-f(pts[i])) / dx
  return (D(f, depth - 1, pts, dx, i + 1) - \
         D(f, depth - 1, pts, dx, i)) / dx

a, b = 5, 10
n = 1000
dx = (b - a) / n
points = [a + i * dx for i in range(0, n + 1)]
print(D(f2, 0, points, dx, 0))
