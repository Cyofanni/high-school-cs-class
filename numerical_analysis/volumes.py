import numpy as np

def f(x):
  return x ** 2 - 4 * x + 5

def vol_slices(f, a, b, n):
  dx = (b - a) / n
  xs = [a + i * dx for i in range(n)]
  ys_sq = [f(x) ** 2 for x in xs]
  return np.pi * dx * sum(ys_sq)

print(vol_slices(f, 1, 4, 1000))
print(78 * np.pi / 5)
