import math

def exhaustion_pi(max_iters):
  alpha = math.radians(90)
  for n in range(2, max_iters):
    area = 2 ** n * (math.sin(alpha) / 2)
    print(area)
    alpha = alpha / 2
  return area

exhaustion_pi(100)
print()
print("math.pi: ", math.pi)
