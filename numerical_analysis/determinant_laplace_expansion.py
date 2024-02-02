import numpy as np, random

def det_laplace(A, i):
    if i >= A.shape[0]:
        raise Exception("out of range")

    if A.shape[0] == 2:
        return A[0][0] * A[1][1] - A[0][1] * A[1][0]

    s = 0
    for j in range(A.shape[1]):
        M_i_j = np.delete(A, i, 0)    #delete i-th row from A
        M_i_j = np.delete(M_i_j, j, 1)    #delete j-th column from M_i_j
        row = random.randint(0, M_i_j.shape[0] - 1)
        s = s + (-1) ** (i + j) * A[i][j] * det_laplace(M_i_j, row)

    return s

#A = np.array([[1, 2, 3, -3.5, 14], [7, 62, 5, 1, 0.25],
#              [4, 8, 7, -50, 81], [7, 6, 1, 9, 12],
#              [5, 6, 2.4, -1.3, 1]])
A = np.array([[6,8,9,3,1],[8.7,5,7,6,4],[4,7.6,8,0.43,9],[1.2,6,8,2,3],
               [1,5,6,7.1,1]], dtype = float)

print(np.linalg.det(A))
print()
print(det_laplace(A, 3))

print()
B = np.array([[random.randint(0, 10) for _ in range(10)] for _ in range(10)])
print(B)
print(det_laplace(B, 0))
