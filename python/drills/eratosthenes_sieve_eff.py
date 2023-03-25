import math#, sympy

limit = 1000
sqrt_limit = int(math.sqrt(limit))
numbers = [num for num in range(2, limit + 1)]
len_numbers = len(numbers)

#functional
primes_filt = filter(sympy.isprime, numbers)
primes_prim_test = list(primes_filt)

for n in range(2, sqrt_limit + 1):
    numbers = list(filter(lambda x: x == n or x % n != 0,
                   numbers))

primes_erat = numbers
print(primes_erat)
print(primes_erat == primes_prim_test)

#pop numbers
i = 0
while i < sqrt_limit:
    if i < sqrt_limit - 1:
        j = i + 1
        while j < len_numbers:
            if numbers[j] % numbers[i] == 0:
                print(numbers[j], numbers[i])
                numbers.pop(j)
                len_numbers -= 1
            j += 1
    i += 1

print(numbers)
