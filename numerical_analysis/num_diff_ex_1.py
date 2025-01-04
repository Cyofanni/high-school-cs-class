import numpy as np

#useful example to teach implicit differentiation

#circle equation in explicit form (positive only)
def f1(x, r):
  return np.sqrt(r ** 2 - x ** 2)

#circle equation in explicit form (negative only)
def f2(x, r):
  return -np.sqrt(r ** 2 - x ** 2)

radius = 5
a, b = -radius, radius
n = 100
dx = (b - a) / n
xs = [a + i * dx for i in range(n + 1)]
df1_dx = [(f1(xs[i], radius) - f1(xs[i - 1], radius)) / dx \
          for i in range(1, len(xs) - 1)]
df2_dx = [(f2(xs[i], radius) - f2(xs[i - 1], radius)) / dx \
          for i in range(1, len(xs) - 1)]

for item in zip(xs, df1_dx):
  print(item, end = '')
  print(',')
print()
for item in zip(xs, df2_dx):
  print(item, end = '')
  print(',')
