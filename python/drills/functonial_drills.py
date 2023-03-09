def factorial(num):
    accumulator = 1
    for i in range(num, 0, -1):
        accumulator *= i
    return accumulator

'''powers_of_2 = [0, 2, 4, 8, 16, 32, 64, 128, 512]
   convert each item into binary
'''
#old-style way
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
