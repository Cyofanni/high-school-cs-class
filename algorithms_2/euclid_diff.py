import sympy

def eucl_diff(a, b):
  while b != 0:
    if a >= b:
      diff = a - b
    else:
      diff = b - a
    a = b
    b = diff

  return a

while True:
  a = int(input())
  b = int(input())
  print(eucl_diff(a, b))
  print(sympy.gcd(a, b))
  print()
