import numpy as np

def taylor_sin(x, n):    #n: degree of polynomial
  acc = 0
  num = x
  den = 1
  sign = 1
  for i in range(1, n + 1, 2):
    print(i, num, den)
    acc += sign * num / den
    num = num * x ** 2
    den = den * (i + 1) * (i + 2)
    sign = -sign
  print()
  return acc

print(taylor_sin(0.8, 11))
print(np.sin(0.8))
