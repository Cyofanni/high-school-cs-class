import numpy as np

def inversion(A):
  n = A.shape[0]
  AI = np.hstack((A, np.identity(n)))
  n1 = AI.shape[1]

  #gauss-jordan
  #forward elimination
  for i in range(n):
    p = AI[i, i]
    for j in range(i + 1, n):
      l = AI[j, i] / p
      for k in range(i, n1):
        AI[j, k] = AI[j, k] - l * AI[i, k]

  #backward elimination
  for i in range(n - 1, -1, -1):
    p = AI[i, i]
    for j in range(i - 1, -1, -1):
      l = AI[j, i] / p
      for k in range(n1 - 1, -1, -1):
        AI[j, k] = AI[j, k] - l * AI[i, k]

  for i in range(n):
    p = AI[i, i]
    for j in range(n1):
      AI[i, j] = AI[i, j] / p

  return AI[0 : n, n : n1]

A = np.array([[1,0.2,6,0.6],[0.1,-4,2,1.5],[2,2,-3,-2],[-2,-2,-6,-4]],
               dtype = float)
A1 = A.copy()
A_inv = inversion(A)
print(A_inv)
print()
print(np.linalg.inv(A1))
