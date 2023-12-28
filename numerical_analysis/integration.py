import math, numpy as np
from sympy import *

#symbolic/analytical integration
x = Symbol('x')

#integral exists but does not have a simple analytical expression
i = integrate(sin(x) / x)
print(i)

#methods for numerical integration (quadrature)
def rectangle_rule_l(f, a, b, n):
  h = (b - a) / n
  xs = [a + i * h for i in range(n)]
  s = 0
  ys = [f(x) for x in xs]
  return sum(ys) * h

def rectangle_rule_r(f, a, b, n):
  h = (b - a) / n
  xs = [a + i * h for i in range(1, n + 1)]
  s = 0
  ys = [f(x) for x in xs]
  return sum(ys) * h

print()
print('integral(x ** 2 + x + 1)dx|(0, 6)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: x ** 2 + x + 1, 0, 6, 40))
print('  known value:')
print('  ', float(integrate(x ** 2 + x + 1, (x, 0, 6))))

print()
print('integral(e ** (2 * x))dx|(2, 5)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: math.exp(2 * x), 2, 5, 40))
print('  known value:')
print('  ', float(integrate(exp(2 * x), (x, 2, 5))))

print()
print('integral(cos(x))dx|(0, 2 * pi)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: math.cos(x), 0, math.pi, 40))
print('  known value:')
print('  ', float(integrate(cos(x), (x, 0, 2 * pi))))

print()
print('integral(3 * x)dx|(-1, 0)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: 3 * x, -1, 0, 80))
print('  known value:')
print('  ', float(integrate(3 * x, (x, -1, 0))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: math.sin(math.log(x)), 5, 10, 80))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: math.sin(math.log(x)), 5, 10, 80))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))
