import numpy as np

def matrix_mult(A, B):
    n_rows_A, n_cols_A = A.shape[0], A.shape[1]
    n_rows_B, n_cols_B = B.shape[0], B.shape[1]
    C = np.array([[0 for _ in range(n_cols_B)] for _ in range(n_rows_A)])
    n_rows_C, n_cols_C = C.shape[0], C.shape[1]

    for i in range(n_rows_C):
        for j in range(n_cols_C):
            for k in range(n_cols_A):
                C[i][j] += A[i][k] * B[k][j]

    return C

A = np.array([[3,5,1,3],
              [1,2,3,4],
              [4,5,6,8],
              [7,8,9,3]]
             )
B = np.array([[4,1,2,3],
              [1,2,1,6],
              [2,4,6,2],
              [6,2,5,4]]
             )

print(matrix_mult(A, B))
