#!usr/bin/python3
import sys
import math
import time

def factorize(n):
    factors = []
    while n != 1:
        i = 2
        found_factor = False
        sq_n = math.sqrt(n)
        while i <= sq_n and found_factor == False:
            if n % i == 0:
                found_factor = True
                factors.append(i)
                n = n // i
            i += 1
        if i > sq_n:
            factors.append(n)
            n = n // n

    return factors

if len(sys.argv) < 2:
    exit("missing number to test")

start_time = time.time()
number = int(sys.argv[1])

prime_factors = factorize(number)
print('prime factors, with multiplicities are:', prime_factors)
print("------ naive factorization took %s seconds to produce a result ------" %
       (time.time() - start_time))
