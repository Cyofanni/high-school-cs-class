import numpy as np

def f0(x):
  return np.sin(x) + np.exp(x)

def arc_length_numerical(f, a, b, n):
  dx = (b - a) / n
  xs = [a + i * dx for i in range(0, n + 1)]
  ys = [f(x) for x in xs]
  ls = [np.sqrt((xs[i]-xs[i-1])**2 + (ys[i]-ys[i-1])**2) for i in range(1, n + 1)]
  return sum(ls)

print(arc_length_numerical(f0, -6, 6, 100))
