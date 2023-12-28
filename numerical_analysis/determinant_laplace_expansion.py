import numpy as np

#only along the 0-th row
def det_laplace(A):
    if len(A) == 1:
        return A[0][0]
    s = 0
    for j in range(len(A)):
        M_0_j = np.delete(A, 0, 0)
        M_0_j = np.delete(M_0_j, j, 1)
        s = s + (-1) ** j * A[0][j] * det_laplace(M_0_j)

    return s

A = np.array([[1, 2, 3, -3.5, 14], [7, 62, 5, 1, 0.25],
              [4, 8, 7, -50, 81], [7, 6, 1, 9, 12],
              [5, 6, 2.4, -1.3, 1]])

print(np.linalg.det(A))
print()
print(det_laplace(A))
