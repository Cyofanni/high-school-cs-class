import numpy as np, random, time

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

    a, b, c, d = split_n_2(A)
    e, f, g, h = split_n_2(B)
    p0 = strassen(a + d, e + h)
    p1 = strassen(c + d, e)
    p2 = strassen(a, f - h)
    p3 = strassen(d, g - e)
    p4 = strassen(a + b, h)
    p5 = strassen(c - a, e + f)
    p6 = strassen(b - d, g + h)

    c_00 = p0 + p3 - p4 + p6
    c_01 = p2 + p4
    c_10 = p1 + p3
    c_11 = p0 - p1 + p2 + p5

    return np.vstack((np.hstack((c_00,c_01)), np.hstack((c_10,c_11))))

size = 2048
A = np.array([[random.randint(0, size)] * size for _ in range(size)])
B = np.array([[random.randint(0, size)] * size for _ in range(size)])

start_time = time.time()
res4 = A.dot(B)
end_time = time.time()
print('built-in (dot):', end_time - start_time)

start_time = time.time()
res5 = np.matmul(A, B)
end_time = time.time()
print('built-in (matmul):', end_time - start_time)

start_time = time.time()
res3 = strassen(A, B)
end_time = time.time()
print('strassen:', end_time - start_time)

start_time = time.time()
res1 = matrix_mult_brute_force(A, B)
end_time = time.time()
print('brute-force:', end_time - start_time)

start_time = time.time()
res2 = matrix_mult_div_n_con(A, B)
end_time = time.time()
print('divide-and-conquer:', end_time - start_time)

print(np.all(res3 == res4) == True)
print(np.all(res2 == res4) == True)
