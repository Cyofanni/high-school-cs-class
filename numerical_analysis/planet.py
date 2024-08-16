#feynman lectures on physics: vol. 1, chapter 9-7
import numpy as np
from matplotlib import pyplot as plt

n_pts = 410
x = [0] * n_pts
x[0] = 0.5
y = [0] * n_pts
vx = 0
vy = 1.630
h = 0.01
rc = (np.sqrt(x[0] ** 2 + y[0] ** 2)) ** 3
print(0, x[0], y[0], vx, vy, rc)

for i in range(1, n_pts):
    vx = vx - h * (x[i - 1] / rc)
    vy = vy - h * (y[i - 1] / rc)
    x[i] = x[i - 1] + h * vx
    y[i] = y[i - 1] + h * vy
    rc = (np.sqrt(x[i] ** 2 + y[i] ** 2)) ** 3
    print(i * h, x[i], y[i], vx, vy, rc)

plt.plot(x, y)
plt.show()


