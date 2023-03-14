import math

def binary_search(lst, key):
    lst_sorted = sorted(lst)
    low = 0
    high = len(lst_sorted) - 1
    found = False

    while low <= high and not found:
        middle = (low + high) // 2
        if lst_sorted[middle] == key:
            found = True
        elif key > lst_sorted[middle]:
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

def merge_1(lst, low, middle, high):
    size = high - low + 1
    left = lst[low:middle + 1]
    left.append(math.inf)
    right = lst[middle + 1:high + 1]
    right.append(math.inf)

    left_index = 0
    right_index = 0
    for i in range(low, high + 1):
        if left[left_index] <= right[right_index]:
            lst[i] = left[left_index]
            left_index = left_index + 1
        else:
            lst[i] = right[right_index]
            right_index = right_index + 1

def merge_sort(lst, low, high):
    if low < high:
        middle = (low + high) // 2
        merge_sort(lst, low, middle)
        merge_sort(lst, middle + 1, high)
        merge_1(lst, low, middle, high)

#binary search
print('binary search: ')
l1 = [5, 1, 8, 3, 5, 3, 9, 12, 13]
l2 = [8, 1, 8, 3, 5, 3, 9, 12, 13, 12, 24, 56, 45]
l3 = ['mozart', 'beethoven', 'bach', 'the beatles',
      'the rolling stones', 'vivaldi']
print(binary_search(l1, 5))
print(l1)
print(binary_search(l2, 56))
print(binary_search(l3, 'vivaldi'))
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
print(merge([2], [1]))

#merge sort
print()
print('merge sort')
ls = [1, 2, 3, 1, 7, 6, 4, 8, 9, 6, 41, 7, 6, 34]
ls1 = [1, 2, 3, 1, 7, 6, 4, 8, 9, 6, 41, 7, 6, 34]
ls1.sort()
print(ls)
merge_sort(ls, 0, len(ls) - 1)
print(ls)
print(ls1)
