#ein jeder numerus par eine summa duorum primorum sey, halte ich
#für ein ganz gewisses theorema, ungeachtet
#ich dasselbe nicht demonstriren kann. (Euler)

from sympy import *

def goldbach(n):
    if n % 2 == 0:
        i = n - 1
        found_pair = False
        while found_pair == False:
            if isprime(i):
                j = n - i
                if isprime(j):
                    found_pair = True
                    pair = (i, j)
            i -= 1
        return pair
    else:
        return -1

for i in range(4, 5001, 2):
    p = goldbach(i)
    print(i, '=', p[0], '+', p[1])
