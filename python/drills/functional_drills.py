def factorial(num):
    accumulator = 1
    for i in range(num, 0, -1):
        accumulator *= i
    return accumulator

'''powers_of_2 = [0, 2, 4, 8, 16, 32, 64, 128, 512]
   convert each item into binary
'''
#old-style
powers_of_2 = [0, 2, 4, 8, 16, 32, 64, 128, 512]
i = 0
while i < len(powers_of_2):
    print(bin(powers_of_2[i]))
    i += 1
print()

#more pythonic style
for num in powers_of_2:
    print(bin(num))
print()

#functional style
map_bin_conv = map(bin, powers_of_2)
for i in map_bin_conv:
    print(i)

print()
#map factorial over list
numbers = [0, 1, 2, 3, 4, 5, 6, 7]
map_fact = map(factorial, numbers)
for f in map_fact:
    print(f)

#list comprehension
interval1 = [i for i in range(10)]
print(interval1)
interval2 = [i for i in range(-10, 11)]
print(interval2)
powers_of_2 = [2**e for e in range(13)]
print(powers_of_2)
times_table_2 = [2*m for m in range(11)]
print(times_table_2)

#'quadratic' list comprehension
print()
times_tables = [[num*t for t in range(1, 11)] for num in range(1, 11)]
for times_table in times_tables:
    print(times_table)

