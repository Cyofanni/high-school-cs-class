import numpy as np

A = np.array([[6,5,1],[1,3,5],[7,5,3],[5,9,-1]])
B = np.array([[5,1,9,6],[-1,-3,8,1],[1,9,0,12]])
C1 = np.array([[0] * A.shape[0]] * B.shape[1])

#fill C1 by rows
for row_C1 in range(C1.shape[0]):
  for col_C1 in range(C1.shape[1]):
    for ind_vec in range(A.shape[1]):
      C1[row_C1, col_C1] += A[row_C1, ind_vec] * B[ind_vec, col_C1]
print(C1)
print()

#fill C2 by columns
C2 = np.array([[0] * A.shape[0]] * B.shape[1])
for col_C2 in range(C2.shape[1]):
  for row_C2 in range(C2.shape[0]):
    for ind_vec in range(A.shape[1]):
      C2[row_C2, col_C2] += A[row_C2, ind_vec] * B[ind_vec, col_C2]
print(C2)
print()

#given k, then fill C by rows (1 component of dot product per iteration)
C3 = np.array([[0] * A.shape[0]] * B.shape[1])
for ind_vec in range(A.shape[1]):
  for row_C3 in range(C3.shape[0]):
    for col_C3 in range(C3.shape[1]):
      C3[row_C3, col_C3] += A[row_C3, ind_vec] * B[ind_vec, col_C3]
  print(C3)
print()
