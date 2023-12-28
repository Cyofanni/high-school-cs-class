import numpy as np, random

def jacobi(A, b, max_iters):
    x_0 = [random.randint(0, 10) for _ in range(len(b))]
    x_1 = [0 for _ in range(len(b))]

    for t in range(max_iters):
        for i in range(len(A)):
            s = 0
            for j in range(len(A)):
                if j != i:
                    s = s + A[i][j] * x_0[j]
            x_1[i] = (b[i] - s) / A[i][i]
        x_0 = x_1

    return x_1

def gauss_seidel(A, b, max_iters):
    x = [random.randint(0, 10) for _ in range(len(b))]

    for t in range(max_iters):
        for i in range(len(A)):
            s = 0
            for j in range(len(A)):
                if j != i:
                    s = s + A[i][j] * x[j]
            x[i] = (b[i] - s) / A[i][i]

    return x

A = np.array([[-80, -20, 1, 2], [2, 90, 0, 1], [1, 1, -35, 10],
              [2, 3.14, 42, 100.12]])
b = np.array([11, 30, -9, 20])

print(np.linalg.solve(A, b))
print(jacobi(A, b, 100))
print(gauss_seidel(A, b, 10))
