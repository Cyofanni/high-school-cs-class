'''
  You are a participant in the RSA public-key cryptosytem, follow these steps:
  1- get two large prime numbers, p and q
  2- compute n = p * q and phi(n) = phi(p * q) = phi(p) * phi(q) = (p - 1) * (q - 1)
  3- select a small odd integer e such that gcd(e, phi(n)) = 1
  4- compute d as the modular inverse of e, modulo phi(n)
  5- publish PUBLIC_KEY = (e, n) (the RSA public key)
  6- keep secret the pair PRIVATE_KEY = (d, n) (the RSA private key)

  phi(n) is difficult to compute without knowing the factors.

  Now, let P be the plaintext, encoded as a number. Let 'E' be the 'encrypting function',
  and 'D' be the 'decrypting function'. E and D are defined as follows:
  E(P): P^e (mod n) ---> produces C, the ciphertext
  D(C): C^d (mod n) ---> produces P, the original plaintext
  This procedure can be shown to be correct.

'''
import sympy

#p = sympy.randprime(10**5, 10**6)
#q = sympy.randprime(10**5, 10**6)
p = sympy.randprime(10**50, 10**60)
q = sympy.randprime(10**50, 10**60)

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
#print("phi_n:", phi_n)
print("RSA public_key:", public_key)
print("RSA private_key:", private_key)
