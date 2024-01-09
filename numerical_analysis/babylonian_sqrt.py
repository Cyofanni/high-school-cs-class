import math

n = 3425231

i = 1
x = 9

while i <= 32:
  x = 0.5 * (x + n / x)
  i += 1

print(x)
print(math.sqrt(n))
