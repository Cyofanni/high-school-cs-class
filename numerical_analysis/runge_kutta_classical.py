import numpy as np

def f0(t, y):
  return y - t**2 + 1

def rk4(f, t0, y0, n, final):
  h = (final - t0) / n
  ts = [t0 + i * h for i in range(n + 1)]
  ys = [0] * (n + 1)
  ys[0] = y0
  for n in range(1, n + 1):
    k1 = f(ts[n-1], ys[n-1])
    k2 = f(ts[n-1] + h/2, ys[n-1] + (h/2)*k1)
    k3 = f(ts[n-1] + h/2, ys[n-1] + (h/2)*k2)
    k4 = f(ts[n-1] + h, ys[n-1] + h*k3)
    ys[n] = ys[n-1] + (h/6)*(k1 + 2*k2 + 2*k3 + k4)

  return ts, ys

res = rk4(f0, 0, 0.5, 4, 2)
for t, y in zip(res[0], res[1]):
  print(t, y)
