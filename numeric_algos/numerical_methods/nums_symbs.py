from sympy import *
import sympy, numpy, math
from scipy.optimize import fsolve
sympy.init_printing() #useless in Colab

#difference between numbers and symbols
print('numbers vs symbols')
print(math.pi)
print(sympy.pi)
print(math.sqrt(2))
print(sympy.sqrt(2))
print()

#binomial expansion
print('binomial expansion')
a, b = symbols('a b')
expr = a + b
for e in range(0, 6):
  print(expand(expr ** e))
print()

#solve equations analitically
x = symbols('x')
sols = solve('x ** 2 - 9', x)
print('analytical solutions of x^2 - 9 = 0', sols)
sols = solve('x ** 2 + 1', x)
print('analytical solutions of x ^ 2 + 1 = 0', sols)
#sols = solve('sin(3*x) - x', x)
#print(sols)
print()

#find roots numerically
f = lambda x: numpy.sin(3*x) - x
sols = fsolve(f, [-10, 10])
print('numerical solutions of sin(3x) = x')
