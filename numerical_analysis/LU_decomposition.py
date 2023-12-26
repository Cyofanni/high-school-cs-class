import numpy as np

def LU_decomposition(A):
    n = len(A)
    L = [[0 for _ in range(n)] for _ in range(n)]
    U = [[0 for _ in range(n)] for _ in range(n)]
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

A = [[2,3,1,5],[6,13,5,19],[2,19,10,23],[4,10,11,31]]
for row in A:
    print(row)
print()
L = LU_decomposition(A)[0]
U = LU_decomposition(A)[1]

for row in L:
    print(row)
print()
for row in U:
    print(row)

print()
prod = np.matmul(L, U)
for row in prod:
    print(row)
