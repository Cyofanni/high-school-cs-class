import math, numpy as np
from sympy import *

#symbolic/analytical integration
x = Symbol('x')

#integral exists but does not have a simple analytical expression
i = integrate(sin(x) / x)
print(i)

#methods for numerical integration (quadrature)

#rectangle rule (left)
def rectangle_rule_l(f, a, b, n):
  h = (b - a) / n
  xs = [a + i * h for i in range(n)]
  s = 0
  ys = [f(x) for x in xs]

  return sum(ys) * h

#rectangle rule (right)
def rectangle_rule_r(f, a, b, n):
  h = (b - a) / n
  xs = [a + i * h for i in range(1, n + 1)]
  s = 0
  ys = [f(x) for x in xs]

  return sum(ys) * h

#rectangle rule (midpoint)
def rectangle_rule_m(f, a, b, n):
  h = (b - a) / n
  xs = [a + h * (i + 0.5) for i in range(0, n)]
  ys = [f(x) for x in xs]

  return sum(ys) * h

#trapezoidal rule (without optimization)
def trapezoidal_rule(f, a, b, n):
  h = (b - a) / n
  xs = [a + i * h for i in range(0, n + 1)]
  ys = [f(x) for x in xs]
  s = 0
  for i in range(1, len(ys)):
    s = s + h * (ys[i] + ys[i - 1]) / 2

  return s

#trapezoidal rule (with optimization)
def trapezoidal_rule_opt(f, a, b, n):
  h = (b - a) / n
  s = 0
  for i in range(1, n):
    s += f(a + i * h)

  return (h / 2) * (f(a) + f(b) + 2 * s)

#kepler-cavalieri-simpson (without optimization)
def kepler_cavalieri_simpson_rule(f, a, b, n):
  h = (b - a) / n
  s = 0
  xs = [a + i * h for i in range(n + 1)]
  for i in range(len(xs) - 1):
    m = (xs[i] + xs[i + 1]) / 2
    s = s + ((xs[i + 1] - xs[i]) / 6) * (f(xs[i]) + 4 * f(m) + f(xs[i + 1]))

  return s

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
print('integral(e ** (2 * x))dx|(2, 5)')
print('  rectangle rule (midpoint):')
print('  ', rectangle_rule_m(lambda x: math.exp(2 * x), 2, 5, 40))
print('  known value:')
print('  ', float(integrate(exp(2 * x), (x, 2, 5))))

print()
print('integral(e ** (2 * x))dx|(2, 5)')
print('  trapezoidal rule:')
print('  ', trapezoidal_rule(lambda x: math.exp(2 * x), 2, 5, 40))
print('  trapezoidal rule - opt:')
print('  ', trapezoidal_rule_opt(lambda x: math.exp(2 * x), 2, 5, 40))
print('  known value:')
print('  ', float(integrate(exp(2 * x), (x, 2, 5))))

print()
print('integral(e ** (2 * x))dx|(2, 5)')
print('  kepler-cavalieri-simpson rule:')
print('  ', kepler_cavalieri_simpson_rule(lambda x: math.exp(2 * x), 2, 5, 40))
print('  known value:')
print('  ', float(integrate(exp(2 * x), (x, 2, 5))))

print('\n################')

print()
print('integral(cos(x))dx|(0, 2 * pi)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: math.cos(x), 0, math.pi, 40))
print('  known value:')
print('  ', float(integrate(cos(x), (x, 0, 2 * pi))))

print()
print('integral(3 * x)dx|(-1, 0)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: 3 * x, -1, 0, 40))
print('  known value:')
print('  ', float(integrate(3 * x, (x, -1, 0))))

print()
print('integral(3 * x)dx|(-1, 0)')
print('  rectangle rule (midpoint):')
print('  ', rectangle_rule_m(lambda x: 3 * x, -1, 0, 40))
print('  known value:')
print('  ', float(integrate(3 * x, (x, -1, 0))))

print()
print('integral(3 * x)dx|(-1, 0)')
print('  trapezoidal rule:')
print('  ', trapezoidal_rule(lambda x: 3 * x, -1, 0, 40))
print('  trapezoidal rule - opt:')
print('  ', trapezoidal_rule_opt(lambda x: 3 * x, -1, 0, 40))
print('  known value:')
print('  ', float(integrate(3 * x, (x, -1, 0))))

print()
print('integral(3 * x)dx|(-1, 0)')
print('  kepler-cavalieri-simpson rule:')
print('  ', kepler_cavalieri_simpson_rule(lambda x: 3 * x, -1, 0, 40))
print('  known value:')
print('  ', float(integrate(3 * x, (x, -1, 0))))

print('\n################')

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  rectangle rule (midpoint):')
print('  ', rectangle_rule_m(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  trapezoidal rule:')
print('  ', trapezoidal_rule(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  trapezoidal rule - opt:')
print('  ', trapezoidal_rule_opt(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print()
print('integral(sin(ln(x)))dx|(5, 10)')
print('  kepler-cavalieri-simpson rule:')
print('  ', kepler_cavalieri_simpson_rule(lambda x: math.sin(math.log(x)), 5, 10, 40))
print('  known value:')
print('  ', float(integrate(sin(log(x)), (x, 5, 10))))

print('\n################')

print()
print('integral(cos(x) + ln(x))dx|(10, 40)')
print('  rectangle rule (left):')
print('  ', rectangle_rule_l(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  known value:')
print('  ', float(integrate(cos(x) + log(x), (x, 10, 40))))

print()
print('integral(cos(x) + ln(x))dx|(10, 40)')
print('  rectangle rule (right):')
print('  ', rectangle_rule_r(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  known value:')
print('  ', float(integrate(cos(x) + log(x), (x, 10, 40))))

print()
print('integral(cos(x) + ln(x))dx|(10, 40)')
print('  rectangle rule (midpoint):')
print('  ', rectangle_rule_m(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  known value:')
print('  ', float(integrate(cos(x) + log(x), (x, 10, 40))))

print()
print('integral(cos(x) + ln(x))dx|(10, 40)')
print('  trapezoidal rule:')
print('  ', rectangle_rule_m(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  trapezoidal rule - opt:')
print('  ', rectangle_rule_m(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  known value:')
print('  ', float(integrate(cos(x) + log(x), (x, 10, 40))))

print()
print('integral(cos(x) + ln(x))dx|(10, 40)')
print('  kepler-cavalieri-simpson rule:')
print('  ', kepler_cavalieri_simpson_rule(lambda x: math.cos(x) + math.log(x), 10, 40, 10))
print('  known value:')
print('  ', float(integrate(cos(x) + log(x), (x, 10, 40))))
