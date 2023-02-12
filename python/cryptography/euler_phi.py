import sys, sympy

#34234862984723345323423414234563546365234241098798665782537424
print('enter an integer (p): ', end = '')
p = int(input())
print('enter an integer (q): ', end = '')
q = int(input())

if sympy.gcd(p, q) == 1:
    print('if p and q are coprime, phi(p*q) = phi(p) * phi(q): ', end = '')
    print(sympy.totient(p * q) == sympy.totient(p) * sympy.totient(q))
else:
    print('input numbers are not coprime')
