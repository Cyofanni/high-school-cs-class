import sys, sympy

print('enter an integer (a): ', end = '')
a = int(input())
print('enter the modulus (n): ', end = '')
n = int(input())

if sympy.gcd(a, n) == 1:
    print('if a and n are coprime, euler\'s theorem states that (a^phi(n)) mod n is equal to: ', end = '')
    print((a ** sympy.totient(n)) % n)
    print('hence, the modular inverse of a is a^(phi(n) - 1), which is equal to: ', end = '')
    print((a ** (sympy.totient(n) - 1)) % n)
else:
    print('input numbers must be coprime')
