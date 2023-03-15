#build a list with the factorizations of the numbers in the interval
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
