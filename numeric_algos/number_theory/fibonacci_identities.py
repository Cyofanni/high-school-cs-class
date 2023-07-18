import sympy, random

F = [sympy.fibonacci(i) for i in range(64)]

#taken from D. Knuth, The Art of Computer Programming

#identity 1
# F_(n+1) * F_(n-1) - (F_n)^2 = (-1)^n
for i in range(1, 63):
  diff = F[i + 1] * F[i - 1] - F[i] ** 2
  print(diff, (-1) ** i)

print('\n\n')

#theorem - Lucas: gcd(F_m, F_n) = F_gcd(m, n)
for i in range(100):
  m = random.randint(0, 63)
  n = random.randint(0, 63)
  g1 = sympy.gcd(F[m], F[n])
  g2 = F[sympy.gcd(m, n)]
  print(g1, g2)
