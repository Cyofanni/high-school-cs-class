'''
  You are a participant in the RSA public-key cryptosytem, follow these steps:
  1- get two large prime numbers, p and q
  2- compute n = p * q and phi(n) = phi(p * q) = phi(p) * phi(q) = (p - 1) * (q - 1)
  3- select a small odd integer e such that gcd(e, phi(n)) = 1
  4- compute d as the modular inverse of e, modulo phi(n)
  5- publish P = (e, n) (the RSA public key)
  6- keep secret the pair S = (d, n) (the RSA private key)

  phi(n) is difficult to compute without knowing the factors

  P(M) = M^e (mod n)
  S(C) = C^d (mod n)
'''
import sympy

p = sympy.randprime(10**5, 10**6)
q = sympy.randprime(10**5, 10**6)
n = p * q
phi_n = (p - 1) * (q - 1)

e = 3
while sympy.gcd(e, phi_n) != 1:
    e += 2

d = pow(e, -1, phi_n)
public_key = (e, n)
private_key = (d, n)

#print("p:", p)
#print("q:", q)
#print("n:", n)
print("phi_n:", phi_n)
print("RSA public_key:", public_key)
print("RSA private key:", private_key)
