import numpy as np

def rep_sqr(b, e):
  n_iters = int(np.log2(e))
  acc = b
  for i in range(n_iters):
    acc = acc * acc
  return acc

print(rep_sqr(5, 16))
print(5 ** 16)
