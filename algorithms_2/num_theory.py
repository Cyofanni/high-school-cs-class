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

def rep_sq(a, exp_bin):
  res = 1
  for bit in exp_bin:
    if bit == 0:
      res = res * res
    else:
      res = res * res * a
  return res

def gcd_ext_eucl_iter(a, b):
  triples = []
  quotients = []

  while b != 0:
    triples.append([0, 0, 0])
    quotients.append(a // b)
    r = a % b
    a = b
    b = r

  triples.append([a, 1, 0])
  for i in range(len(triples) - 2, -1, -1):
    triples[i][0] = triples[i + 1][0]
    triples[i][1] = triples[i + 1][2]
    triples[i][2] = triples[i + 1][1] - quotients[i] * triples[i + 1][2]

  return triples[0]


print(gcd_ext_eucl_iter(99, 78))
print()
r = rep_sq(3, [1,0,0,1,1])
print(r, 3 ** 19)
print()
#print(is_prime(34598672233309548723054829365798672361154598672239919548453054829365734592387867236231))
print(factorize(4))
sv = erat_sieve(10)

for pair in sv:
  print(pair)
