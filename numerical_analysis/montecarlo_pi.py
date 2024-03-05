import math, random

n_points = 10000
n_circle_points = 0

for i in range(n_points):
  p = (random.uniform(0, 1), random.uniform(0, 1))
  dist_origin = math.sqrt(p[0] ** 2 + p[1] ** 2)
  if dist_origin < 1:
    n_circle_points += 1

print((n_circle_points / n_points) * 4)
