#usage python3 factorization.py 3463
#      python3 factorization.py 98762341456423464716871998671345894

#!usr/bin/python3
import sys
import math
import time
import sympy

def factorize(n):
    factors = []
    if n == 0:
        factors.append(n)
    else:
        while n != 1:
            i = 2
            found_factor = False
            sq_n = int(math.sqrt(n))
            while i <= sq_n and found_factor == False:
                if n % i == 0:
                    found_factor = True
                    factors.append(i)
                    n = n // i
                i += 1
            if found_factor == False:
                factors.append(n)
                n = n // n

    return factors

if len(sys.argv) < 2:
    exit("missing number to factorize")

start_time = time.time()
number = int(sys.argv[1])

prime_factors = factorize(number)
prime_factors_sympy = sympy.factorint(number)
print('prime factors, with multiplicities (sympy computation) are:', prime_factors_sympy)
print('prime factors, with multiplicities (naive algorithm) are:', prime_factors)

#print("------ naive factorization took %s seconds to produce a result ------" %
       #(time.time() - start_time))
