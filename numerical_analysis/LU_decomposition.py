import numpy as np

def LU_decomposition(A):
    n = A.shape[0]
    L = np.array([[0 for _ in range(n)] for _ in range(n)])
    U = np.array([[0 for _ in range(n)] for _ in range(n)])
    U[0] = A[0].copy()

    for i in range(n):
        U[i][i] = A[i][i]
        L[i][i] = 1
        for j in range(i + 1, n):
            L[j][i] = A[j][i] / U[i][i]
            for k in range(i, n):
                A[j][k] = A[j][k] - L[j][i] * A[i][k]
                U[j][k] = A[j][k]

    return (L, U)

A = np.array([[2,3,1,5],[6,13,5,19],[2,19,10,23],[4,10,11,31]])
print(A)
print()
L, U = LU_decomposition(A)[0], LU_decomposition(A)[1]

print(L)
print()
print(U)

print()
print(np.matmul(L, U))
