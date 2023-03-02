import math

def binary_search(lst, k):
    lst.sort()
    low = 0
    high = len(lst) - 1
    found = False

    while low < high and not found:
        middle = (low + high) // 2
        if lst[middle] == k:
            found = True
        elif k > lst[middle]:
            low = middle + 1
        else:
            high = middle - 1

    return (found, middle)

def fibonacci(num):
    fib = []
    fib.append(0)
    fib.append(1)
    for i in range(2, num):
        fib.append(fib[i - 1] + fib[i - 2])

    return fib

def merge(lst1, lst2):
    lmerged = []
    lst1.append(math.inf)
    lst2.append(math.inf)
    size_lmerged = len(lst1) + len(lst2) - 2
    left_index = 0
    right_index = 0

    for i in range(size_lmerged):
        if lst1[left_index] <= lst2[right_index]:
            lmerged.append(lst1[left_index])
            left_index = left_index + 1
        else:
            lmerged.append(lst2[right_index])
            right_index = right_index + 1

    return lmerged

#binary search
print('binary search: ')
l1 = [5, 1, 8, 3, 5, 3, 9, 12, 13]
l2 = [8, 1, 8, 3, 5, 3, 9, 12, 13, 12, 24, 56, 45]
l3 = ['mozart', 'beethoven', 'bach', 'the beatles',
      'the rolling stones', 'vivaldi']
print(binary_search(l1, 5))
print(binary_search(l2, 56))
print(binary_search(l3, 'bach'))
t = binary_search(l3, 'beethoven')
print(type(t))

#fibonacci numbers
print()
print('fibonacci numbers: ')
for i in range(10):
    print(fibonacci(i))

#merge
print()
print('merge algorithm: ')
print(merge([2, 4, 6, 10, 12], [6, 7, 10, 12, 13, 16, 17, 18, 20, 22]))
print(merge([1, 18], [0, 2, 4]))
