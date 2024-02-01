import numpy as np, random

def jacobi(A, b, max_iters):
    x_0 = np.array([random.randint(0, 10) for _ in range(len(b))],
                    dtype = float)
    x_1 = np.array([0 for _ in range(len(b))], dtype = float)

    for t in range(max_iters):
        for i in range(len(A)):
            s = 0
            for j in range(len(A)):
                if j != i:
                    s = s + A[i][j] * x_0[j]
            x_1[i] = (b[i] - s) / A[i][i]
        x_0 = np.copy(x_1)

    return x_1

def gauss_seidel(A, b, max_iters):
    x = np.array([random.randint(0, 10) for _ in range(len(b))],
                  dtype = float)

    for t in range(max_iters):
        for i in range(len(A)):
            s = 0
            for j in range(len(A)):
                if j != i:
                    s = s + A[i][j] * x[j]
            x[i] = (b[i] - s) / A[i][i]

    return x

#A = np.array([[-80, -20, 1, 2], [2, 90, 0, 1], [1, 1, -35, 10],
#              [2, 3.14, 42, 100.12]])
#b = np.array([11, 30, -9, 20])
A = np.array([[-80, -20, 1], [2, 90, 0], [1, 1, -35]])
b = np.array([11, 30, -9])

print("built-in:")
print(np.linalg.solve(A, b))
print("\njacobi:")
print(jacobi(A, b, 10))
print("\ngauss-seidel:")
print(gauss_seidel(A, b, 10))
