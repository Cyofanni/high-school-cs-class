import numpy as np

A = np.array([[6, 4, -1],
              [-3, -1, 2],
              [-2, 1, 2]])
b = np.array([12, -11, 8])

A1 = np.array([[2, 1, -1],
              [-3, -1, 2],
              [-2, 1, 2]])
b1 = np.array([8, -11, -3])

A2 = np.array([[2, 1, -1, 6],
               [4, -3, -1, 2],
               [-2, 1, 2, 8],
               [6, 6, 2, 8.2]])
b2 = np.array([8, -11, -3, -3])

A3 = np.array([[2, 13, -13, 2],
               [3, -3, -1, 2],
               [-2, 1, 2, 1],
               [3, 12, 2, 8.2]])
b3 = np.array([3, 11, -3, -15])

#solve linear systems
print(np.linalg.solve(A, b))
print(np.linalg.solve(A1, b1))
print(np.linalg.solve(A2, b2))
print(np.linalg.solve(A3, b3))

#compute determinant
print()
print(np.linalg.det(A))

#compute inverse
print()
print(np.linalg.inv(A))
print()
print(np.matmul(A, np.linalg.inv(A)))

#matrix multiplication
print()
C = np.array([[5, 6, 5, 3.3],
              [4, 3, 3.3, 4.1],
              [1, 2, 3, 9]])
D = np.array([[5, 6.8],
              [4, 3.2],
              [1, 2],
              [0, 34]])
print(np.matmul(C, D))
