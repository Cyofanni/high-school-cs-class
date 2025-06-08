import numpy as np
import matplotlib.pyplot as plt

def midpoint(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return (x1 + x2) / 2, (y1 + y2) / 2

def sierpinski(A, B, C, depth):
    if depth == 0:
        return
    AB_mid = midpoint(A, B)
    AC_mid = midpoint(A, C)
    BC_mid = midpoint(B, C)
    triangle = plt.Polygon([AB_mid, AC_mid, BC_mid], color = 'white')
    plt.gca().add_patch(triangle)
    sierpinski(A, AB_mid, AC_mid, depth - 1)
    sierpinski(AB_mid, B, BC_mid, depth - 1)
    sierpinski(AC_mid, BC_mid, C, depth - 1)

side = 50
A, B, C = (0, 0), (side/2, (np.sqrt(3)/2)*side), (side, 0)
fig = plt.figure(figsize=(10, 10))
ax = fig.add_subplot(xlim=[0, side], ylim=[0, B[1]])
ax.set_aspect('equal')
ax.axis('off')
triangle = plt.Polygon([A, B, C], color = 'black')
ax.add_patch(triangle)
sierpinski(A, B, C, 5)

plt.show()
