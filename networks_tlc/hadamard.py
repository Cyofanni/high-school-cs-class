import numpy as np

def hadamard(n):
  if n == 0:
    return np.array([1])
  h_ul = hadamard(n - 1)
  h_lr = -1 * hadamard(n - 1)
  h_u = np.hstack((h_ul, h_ul))
  h_l = np.hstack((h_ul, h_lr))
  return np.vstack((h_u, h_l))

print(hadamard(3))
