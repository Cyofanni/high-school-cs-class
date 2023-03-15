#build a list with factorizations of the numbers in the interval
#[0, 100]. Use the method 'factorint(n)' from the module 'sympy'.
#Rely on list comprehension
import sympy
fs = [sympy.factorint(num) for num in range(0, 101)]
print(fs)

#build a dictionary in this way:
#  {num: (sympy.sqrt(num), math.sqrt(num)}
#  i.e. keys are integers in the range [0, 50], values are tuples containing
#  the square root of num computed both symbolically and numerically
sqrts_sym_num = {num: (sympy.sqrt(num), math.sqrt(num)) for num in range(0, 51)}
for k, v in sqrts.items():
    print(k, v)

#generate a list containing powers of 2 [2**0..2**16], using the bitwise left shift operator
#start with the given list
powers_2 = [1]
for t in range(1, 17):
    powers_2.append(powers_2[t] << 1)
print(powers_2)

#filter prime numbers out of the interval [0..1000]
filt_primes = filter(sympy.isprime, [n for n in range(0, 1001)])
for prime in filt_primes:
    print(prime)
