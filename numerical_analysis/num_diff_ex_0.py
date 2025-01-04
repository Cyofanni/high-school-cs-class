def f(x):
  return x ** x

a, b = 0.1, 10
n = 100
dx = (b - a) / n
xs = [a + i * dx for i in range(n + 1)]
df_dx = [(f(xs[i]) - f(xs[i - 1])) / dx for i in range(1, len(xs) - 1)]

for item in zip(xs, df_dx):
  print(item, end = '')
  print(',')
