#!usr/bin/python3
import sys
import math
import time

def is_prime(n):
    is_prime = True

    if n % 2 == 0 and n != 2 or n == 1:
        is_prime = False

    elif n % 2 != 0 and n > 2:
        trial_div = 3
        found_div = False
        while trial_div <= int(math.sqrt(n)) and found_div == False:
            if n % trial_div == 0:
                is_prime = False
                found_div = True
            trial_div += 2
            
    return is_prime

if len(sys.argv) < 2:
    exit("missing number to test")

start_time = time.time()
#large number: 34598672233309548723054829365798672361154598672239919548453054829365734592387867236231
number = int(sys.argv[1])

if is_prime(number):
    print(number, 'is prime')    
else:
    print(number, 'is not prime')
print("------ trial division took %s seconds to produce a result ------" %
       (time.time() - start_time))
