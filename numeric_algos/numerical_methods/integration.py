import numpy as np
import matplotlib.pyplot as plt
from scipy import integrate
from sympy import *

init_printing()

#symbolic/analytical integration
x = Symbol('x')
i = integrate(x ** 4 + x + 2, x)
i_def = integrate(x ** 4 + x + 2, (x, 0, 6))
print(i)
print(float(i_def))
i = integrate(cos(x))
print(i)

#integral exists but does not have a simple analytical expression
i = integrate(sin(x) / x)
print(i)

#methods for numerical integration
print('########')
def rectangle_rule_l(f, a, b, n):
  b = (b - a) / n
  xs = [a + i * b for i in range(n)]
  s = 0
  ys = [f(x) for x in xs]
  return sum(ys) * b

print(rectangle_rule_l(lambda x: x ** 2 + x + 1, 0, 6, 100))
print(float(integrate(x ** 2 + x + 1, (x, 0, 6))))
