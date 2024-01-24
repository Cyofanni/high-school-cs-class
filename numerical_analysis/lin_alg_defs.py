import numpy as np

def transpose(A):
  nrows_A, ncols_A = A.shape
  nrows_A_T = ncols_A
  ncols_A_T = nrows_A
  A_T = np.array([[0] * ncols_A_T for _ in range(nrows_A_T)])
  for i in range(nrows_A_T):
    for j in range(ncols_A_T):
      A_T[i][j] = A[j][i]

  return A_T

A = np.array([[2,1,-1],[-3,-1,2],[-2,1,-2]])
A_T = transpose(A)
print('A:')
print(A)

print()
print('A_T:')
print(A_T)

print()
print('A_T (built-in):')
A_T_bi = np.transpose(A)
print(A_T_bi)

print()
print(np.all((A_T == A_T_bi) == True))
