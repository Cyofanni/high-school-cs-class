import numpy as np
from matplotlib import pyplot

n = int(2e5)
dt = .1e-3
L = 3
g = 9.81
#time
t = [i * dt for i in range(n)]
#angle
theta = [0] * n
theta[0] = 0.2
#rate of change of angle
theta_1 = [0] * n
theta_1[0] = 0.1

for k in range(1, n):
  theta_1[k] = theta_1[k - 1] + dt * (-g / L) * np.sin(theta[k - 1])
  theta[k] = theta[k - 1] + dt * theta_1[k - 1]

pyplot.plot(t, theta)
pyplot.show()
