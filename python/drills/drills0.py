import math

def binary_search(ls, k):
    ls.sort()
    low = 0
    high = len(ls) - 1
    found = False

    while low < high and found == False:
        middle = (low + high) // 2
        if (ls[middle] == k):
            found = True
        elif k > ls[middle]:
            low = middle + 1
        else:
            high = middle - 1

    return (found, middle)

def fibonacci(n):
    l = []
    l.append(0)
    l.append(1)
    for i in range(2, n):
        l.append(l[i - 1] + l[i - 2])

    return l

def merge(l1, l2):
    lmerged = []
    l1.append(math.inf)
    l2.append(math.inf)
    size_lmerged = len(l1) + len(l2) - 2
    left_index = 0
    right_index = 0

    for i in range(size_lmerged):
        if l1[left_index] <= l2[right_index]:
            lmerged.append(l1[left_index])
            left_index = left_index + 1
        else:
            lmerged.append(l2[right_index])
            right_index = right_index + 1

    return lmerged

#binary search
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
for i in range(10):
    print(fibonacci(i))

#merge
print(merge([2, 4, 6, 10, 12], [6, 7, 10, 12, 13, 16, 17, 18, 20, 22]))
print(merge([1, 18], [0, 2, 4]))
