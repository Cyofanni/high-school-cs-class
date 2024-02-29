import math

def leibniz_pi(max_iters):
  xs = [((-1) ** k) / (2 * k + 1) for k in range(max_iters)]
  return 4 * sum(xs)

print(leibniz_pi(100000))
print(math.pi)
