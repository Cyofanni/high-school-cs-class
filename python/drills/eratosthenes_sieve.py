#sieve of eratosthenes

import sympy

mults = [[num * t for t in range(2, 51)] for num in range(2, 11)]
flattened_mults = [num for sublist in mults for num in sublist]

def not_in_mults(num):
    return num not in flattened_mults

numbers_2_100 = (num for num in range(2, 101))
sieve = filter(not_in_mults, numbers_2_100)

primes_erat = tuple(sieve)
print(primes_erat)

numbers_2_100 = (num for num in range(2, 101))
sieve_is_prime = filter(sympy.isprime, numbers_2_100)
primes_is_prime = tuple(sieve_is_prime)
print(primes_is_prime)

numbers_2_100 = (num for num in range(2, 101))
sieve_lambda = filter(lambda n: n not in flattened_mults,
                      numbers_2_100)
primes_lambda = tuple(sieve_lambda)
