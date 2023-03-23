#drill 0: explain the following code
import math
def e1():
    return math.exp(1)
def e2():
    return math.exp(2)
def e3():
    return math.exp(3)
def e4():
    return math.exp(4)

fs = [e1, e2, e3, e4]
for f in fs:
    print(f())


#drill 1: write a code that implements the logic of the previous drill,
#         using list comprehension


#drill 2: explain the following the code
lt = [([0, 1], [1, 2], [2, 3]), ([0, 2], [1, 3], [2, 4]), ([0, 3], [1, 4], [2, 5]),
      ([0, 4], [1, 5], [2, 6]), ([0, 5], [1, 6], [2, 7])]
for item1 in lt:
    for item2 in item1:
        for item3 in item2:
            print(item3, end = ' ')
        print()
    print()
print()


#drill 3: use filter and list comprehension to generate a list containing
#         prime numbers in the range [0, 1000]. Use sympy.isprime().



#drill 4: use matplotlib to plot the following functions in the proper range.
#use list comprehension.
#         y = ln(x)
#         y = sqrt(x)
#         y = x
#         y = x**2
#         y = x**3
#         y = e**x


#drill 5: explain the following code:
import math
mp = map(math.log, [x for x in range(1, 101)])
for l in mp:
    print(l)
