from sympy import *
a, b, c, d = symbols('a b c d')
expr = a + b
for e in range(0, 8):
  print(expand(expr ** e))

expr1 = a*a + a*b + a*c + a*d
print()
x, y = symbols('x y')
expr1 = x**2 + 2*x*y + y**2
print(factor(expr1))

#solve equations
x = symbols('x')
sols = solve('x**2 - x - 1', x)  #x**2 - x - 1 = 0
print(sols)
sols = solve('x**2 + 9', x)  #x**2 = -9
print(sols)
sols = solve('log(x)')
print(sols)
sols = solve('sin(x) - 1', x)
print(sols)
