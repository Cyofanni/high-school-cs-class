import numpy as np

def gauss_jordan(S):
    nrows, ncols = S.shape
    for i in range(nrows - 1):
        u = S[i][i]
        for j in range(i + 1, nrows):
            l = S[j][i] / u
            for k in range(i, ncols):
                S[j][k] = S[j][k] - l * S[i][k]

def back_substitution(S):
    nrows, ncols = S.shape
    sol = np.zeros(nrows, dtype = float)
    for i in range(nrows - 1, -1, -1):
        a = S[i][i]
        b = S[i][ncols - 1]
        s = 0
        for j in range(i + 1, ncols - 1):
            s += S[i][j] * sol[j]
        sol[i] = (b - s) / a

    return sol

A = np.array([[2.0, 1, -1],
              [-3, -1, 2],
              [-2, 1, 2]],
              dtype = float)
b = np.array([8, -11, -3], dtype = float)
A_b = np.c_[A, b]
print("augmented matrix:\n", A_b)

print()
gauss_jordan(A_b)
print("after gauss-jordan elimination:\n", A_b)
print()
print("solution:", back_substitution(A_b))

print()
print("solution (built-in solver):", end = ' ')
#print(A, b)
print(np.linalg.solve(A, b))
