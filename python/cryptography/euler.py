#usage python3 euler.py a n
import sys, sympy

if len(sys.argv) < 3:
    exit('too few command line arguments')

a = int(sys.argv[1])
n = int(sys.argv[2])

if sympy.gcd(a, n) == 1:
    print('if a and n are coprime, euler\'s theorem states that (a^phi(n)) mod n is equal to: ', end = '')
    print((a ** sympy.totient(n)) % n)
    print('hence, the modular inverse of a is (a^(phi(n) - 1)) % n, which is equal to: ', end = '')
    print((a ** (sympy.totient(n) - 1)) % n)
else:
    print('input numbers must be coprime')
