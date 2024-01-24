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

def is_symmetric(A):
  nrows, ncols = A.shape
  if nrows != ncols:
    return False
  for i in range(nrows):
    for j in range(i + 1, ncols):
      if A[i][j] != A[j][i]:
        return False

  return True

def is_L(A):
  nrows, ncols = A.shape
  if nrows != ncols:
    return False
  for i in range(nrows):
    for j in range(i + 1, ncols):
      if A[i][j] != 0:
        return False

  return True

def is_U(A):
  nrows, ncols = A.shape
  if nrows != ncols:
    return False
  for i in range(nrows):
    for j in range(i):
      if A[i][j] != 0:
        return False

  return True

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

print('\nsymmetric:')
B = np.array([[1,4,7],[4,5,8],[7,8,9]])
print(B)
print(is_symmetric(B))
print(np.transpose(B))

print('\ninverse:')
C = np.array([[-1,1.5],[1,-1]], dtype = float)
print(C)
print()
C_inv = np.linalg.inv(C)
print(C_inv)
print()
print(C.dot(C_inv))

print('\nlower')
print(is_L(np.array([[1,0,0],[2,96,0],[4,9,69]])))
print('\nupper')
print(is_U(np.array([[1,4,1],[0,6,9],[0,0,1]])))
