#Ordinary Differential Equations
from sympy import *
from sympy.abc import x
import math

#solve ODE's algebraically
f = Function('f')
re1 = dsolve(diff(f(x), x) - f(x) + x ** 2 - 1, f(x), ics = {f(0): 0.5})
print('known solution:', re1)
print()
re2 = dsolve(diff(f(x), x) - 2 * f(x), f(x), ics = {f(0): 10})
print('known solution:', re2)

#euler method

def f1(x, y):
  return y - x ** 2 + 1

def f2(x, y):
  return 2 * y

#compare numerical result with known solutions
def solution1(x):
  return (x + 1) ** 2 - 0.5 * math.exp(x)

def solution2(x):
  return 10 * exp(2 * x)

def euler_method(f, a, b, n, w):
  output = [(a, w)]
  step = (b - a) / n
  x = a
  #print('approximation: x:', x, '    f(x):', w)
  #print('solution: x:', x, '    f(x):', solution(x))
  print()
  for i in range(1, n + 1):
    w = w + step * f(x, w)
    output.append((x + step, w))
    x = a + i * step
    #print('approximation: x:', x, '    f(x):', w)
    #print('solution: x:', x, '    f(x):', solution(x))
    #print()

  return output

res = euler_method(f2, 0, 3, 3, 10)
for item in res:
  print(item)
