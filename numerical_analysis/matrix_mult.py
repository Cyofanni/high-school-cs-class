import numpy as np

def matrix_mult_brute_force(A, B):
    n_rows_A, n_cols_A = A.shape[0], A.shape[1]
    n_rows_B, n_cols_B = B.shape[0], B.shape[1]
    C = np.array([[0 for _ in range(n_cols_B)] for _ in range(n_rows_A)])
    n_rows_C, n_cols_C = C.shape[0], C.shape[1]

    for i in range(n_rows_C):
        for j in range(n_cols_C):
            for k in range(n_cols_A):
                C[i][j] += A[i][k] * B[k][j]

    return C

def split_n_2(A):
    n = A.shape[0]
    return A[0:n//2, 0:n//2], A[0:n//2, n//2:n], A[n//2:n, 0:n//2], A[n//2:n, n//2:n]

def matrix_mult_div_n_con(A, B):
    if A.shape[0] <= 2:
        return matrix_mult_brute_force(A, B)

    a, b, c, d = split_n_2(A)
    e, f, g, h = split_n_2(B)
    c_00 = matrix_mult_div_n_con(a, e) + matrix_mult_div_n_con(b, g)
    c_01 = matrix_mult_div_n_con(a, f) + matrix_mult_div_n_con(b, h)
    c_10 = matrix_mult_div_n_con(c, e) + matrix_mult_div_n_con(d, g)
    c_11 = matrix_mult_div_n_con(c, f) + matrix_mult_div_n_con(d, h)
    hblock_0 = np.hstack((c_00, c_01))
    hblock_1 = np.hstack((c_10, c_11))
    return np.vstack((hblock_0, hblock_1))

#https://en.wikipedia.org/wiki/Strassen_algorithm
def strassen(A, B):
    if A.shape[0] <= 2:
        return matrix_mult_brute_force(A, B)

    a_11, a_12, a_21, a_22 = split_n_2(A)
    b_11, b_12, b_21, b_22 = split_n_2(B)
    p1 = strassen(a_11 + a_22, b_11 + b_22)
    p2 = strassen(a_21 + a_22, b_11)
    p3 = strassen(a_11, b_12 - b_22)
    p4 = strassen(a_22, b_21 - b_11)
    p5 = strassen(a_11 + a_12, b_22)
    p6 = strassen(a_21 - a_11, b_11 + b_12)
    p7 = strassen(a_12 - a_22, b_21 + b_22)

    c_00 = p1 + p4 - p5 + p7
    c_01 = p3 + p5
    c_10 = p2 + p4
    c_11 = p1 - p2 + p3 + p6

    return np.vstack((np.hstack((c_00,c_01)), np.hstack((c_10,c_11))))

A = np.array([[3,5,1,3,6,5,3,4],
              [1,2,3,4,1,2,3,8],
              [4,5,6,8,6,5,4,6],
              [7,8,9,3,3,8,7,6],
              [1,9,8,3,4,5,2,1],
              [5,7,56,1,2,3,4,5],
              [1,2,9,-8,6,5,43,3],
              [1,3,9,-8,6,1,47,9]]
             )
B = np.array([[3,5,1,34,6,53,3,4],
              [0,2,1,2,1,2,3,8],
              [0,5,6,8,6,5,4,6],
              [0,8,9,4,3,0,7,6],
              [1,9,8,3,4,5,21,1],
              [5,7,56,1,2,3,43,5],
              [1,2,9,-8,6,5,3,3],
              [3,3,9,8,6,1,40,-1]]
             )

#a, b, c, d = split_n_2(A)
res1 = matrix_mult_brute_force(A, B)
print(res1)
print()
res2 = matrix_mult_div_n_con(A, B)
print(res2)
print()
res3 = strassen(A, B)
print(res3)
print()
res4 = A.dot(B)
print(res4)
print()
res5 = np.matmul(A, B)
print(res5)
print()
print(np.all(res3 == res4) == True)
print(np.all(res2 == res4) == True)
