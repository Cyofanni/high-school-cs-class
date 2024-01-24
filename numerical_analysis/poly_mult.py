from sympy import *

def mult_coeffs(p1, p2):
  deg_p1 = len(p1) - 1
  deg_p2 = len(p2) - 1
  p3 = [0 for _  in range(deg_p1 + deg_p2 + 1)]

  for k in range(len(p3)):
    s = 0
    for j in range(k + 1):
      if j < len(p1) and k - j < len(p2):
        s += p1[j] * p2[k - j]
    p3[k] = s

  return p3

def print_poly(p):
  for k in range(len(p) - 1, -1, -1):
    print(str(p[k]) + '*x**' + str(k), end = '')
    if k > 0:
      print(' + ', end = '')
    k -= 1
  print()

poly_1 = [3, 1, 3, 5]
poly_2 = [2, 3, 2, -8, 7, 15]
print_poly(poly_1)
print_poly(poly_2)
print_poly(mult_coeffs(poly_1, poly_2))

print()
x = Symbol('x')
p1 = 5*x**3 + 3*x**2 + x + 3
p2 = 15*x**5 + 7*x**4 - 8*x**3 + 2*x**2 + 3*x + 2
print(expand(p1 * p2))
