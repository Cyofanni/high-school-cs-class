#the feynman lectures on physics: vol. 1, chapter 9-5

import numpy as np
from matplotlib import pyplot as plt

num_pts = 1500
xs = [0] * num_pts
xs[0] = 1
vs = [0] * num_pts
h = 0.01

for t in range(1, num_pts):
    vs[t] = vs[t - 1] - h * xs[t - 1]
    xs[t] = xs[t - 1] + h * vs[t - 1]

for i in range(num_pts):
    print(h * i, xs[i], vs[i], -xs[i])

ts = [h * t for t in range(num_pts)]
plt.plot(ts, xs)
plt.plot(ts, np.cos(ts))
plt.show()
