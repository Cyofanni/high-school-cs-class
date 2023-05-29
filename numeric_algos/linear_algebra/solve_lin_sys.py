import numpy as np

A = np.array([[6, 4, -1], [-3, -1, 2],
              [-2, 1, 2]])

b = np.array([12, -11, 8])

print(np.linalg.solve(A, b))
