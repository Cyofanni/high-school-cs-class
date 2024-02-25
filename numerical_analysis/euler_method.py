#Ordinary Differential Equations
from sympy import *
from sympy.abc import x
import math

#solve the ODE algebraically
f = Function('f')
result = dsolve(diff(f(x), x) - f(x) + x ** 2 - 1, f(x), ics={f(0): 0.5})
print('known solution:', result)

#euler method

def f(x, y):
  return y - x ** 2 + 1

#compare numerical result with known solution
def solution(x):
  return (x + 1) ** 2 - 0.5 * math.exp(x)

def euler_method(a, b, n, w, f):
  output = []
  step = (b - a) / n
  x = a
  print('approximation: x:', x, '    f(x):', w)
  print('solution: x:', x, '    f(x):', solution(x))
  print()
  for i in range(1, n + 1):
    w = w + step * f(x, w)
    output.append((x, w))
    x = a + i * step
    #print('approximation: x:', x, '    f(x):', w)
    #print('solution: x:', x, '    f(x):', solution(x))
    #print()

  return output

res = euler_method(0, 4, 10, 0.5, f)
for item in res:
  print(item)
