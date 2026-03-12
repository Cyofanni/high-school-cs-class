import math
#from sympy import *

#list(sieve.primerange(100))

def is_prime(n):
  if n == 2:
    return True
  if n == 1 or n % 2 == 0:
    return False

  for d in range(3, int(math.sqrt(n)), 2):
    if n % d == 0:
      return False

  return True

def factorize(n):
  factors = []
  while n != 1:
    div = 2
    found = False
    while div <= n and found == False:
      if n % div == 0:
        n = n / div
        factors.append(div)
        found = True
      div += 1

  return factors

def erat_sieve(n):
  numbers = [k for k in range(2, n + 1)]
  numbers.insert(0, 1)
  numbers.insert(0, 0)
  primalities = [True for _ in range(n + 2)]
  primalities[0], primalities[1] = False, False

  sz = n - 2 + 1 + 2
  for i in range(2, sz - 1):
    num = numbers[i]
    for j in range(i + 1, sz):
      if numbers[j] % num == 0:
        primalities[j] = False

  return zip(numbers, primalities)

#print(is_prime(34598672233309548723054829365798672361154598672239919548453054829365734592387867236231))
print(factorize(4))
sv = erat_sieve(1000)

for pair in sv:
  print(pair)
