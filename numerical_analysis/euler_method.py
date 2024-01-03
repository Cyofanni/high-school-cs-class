#Ordinary Differential Equations
from sympy import *
from sympy.abc import x
import math

#solve the ODE algebraically
f = Function('f')
result = dsolve(diff(f(x), x) - f(x) + x ** 2 - 1, f(x), ics={f(0): 0.5})
print('known solution:', result)

#euler method
def func(x, f_x):
  return f_x - x ** 2 + 1

#compare numerical result, with known solution
def solution(x):
  return (x + 1) ** 2 - 0.5 * math.exp(x)

def euler_method(a, b, N, f_x, func):
  step = (b - a) / N
  x = a
  print('approximation: x:', x, '    f(x):', f_x)
  print('solution: x:', x, '    f(x):', solution(x))
  print()
  for i in range(1, N + 1):
    f_x = f_x + step * func(x, f_x)
    x = a + i * step
    print('approximation: x:', x, '    f(x):', f_x)
    print('solution: x:', x, '    f(x):', solution(x))
    print()

euler_method(0, 2, 100, 0.5, func)
