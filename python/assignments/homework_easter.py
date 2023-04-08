#Ex 0 ###
import random, time, math

numbers = [random.randint(-6000, 6000) for i in range(1000)]
numbers_copy = numbers.copy()
numbers_copy_copy = numbers.copy()

#Ex 1 ###
def insertion_sort(lst):
    lst_size = len(lst)
    for i in range(1, lst_size):
        item = lst[i]
        j = i - 1
        while j >= 0 and item < lst[j]:
            lst[j + 1] = lst[j]
            j = j - 1
        lst[j + 1] = item

start_time = time.time()
insertion_sort(numbers)
end_time = time.time()
print("insertion sort, my implementation: ", end_time - start_time)

start_time = time.time()
numbers_copy.sort()
end_time = time.time()
print("python's sort: ", end_time - start_time)

#Ex 2 ###
def merge(lst, l, m, h):
    left = lst[l:m + 1]
    right = lst[m + 1:h + 1]
    left.append(math.inf)
    right.append(math.inf)

    left_index = 0
    right_index = 0
    for i in range(l, h + 1):
        if left[left_index] <= right[right_index]:
            lst[i] = left[left_index]
            left_index += 1
        else:
            lst[i] = right[right_index]
            right_index += 1

def merge_sort(lst, l, h):
    if l < h:
        m = (l + h) // 2
        merge_sort(lst, l, m)
        merge_sort(lst, m + 1, h)
        merge(lst, l, m, h)

start_time = time.time()
merge_sort(numbers_copy_copy, 0, len(numbers_copy_copy) - 1)
end_time = time.time()
print("merge sort, my implementation: ", end_time - start_time)

#Ex 5 ###
def bubble_sort(lst):
    lst_size = len(lst)
    for i in range(lst_size - 1, 0, -1):
        for j in range(0, i):
            if lst[j] > lst[j + 1]:
                t = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = t

def selection_sort(lst):
    lst_size = len(lst)
    for i in range(0, lst_size):
        min_item = lst[i]
        index_min = i
        for j in range(i + 1, lst_size):
            if lst[j] < min_item:
                min_item = lst[j]
                index_min = j
        t = lst[i]
        lst[i] = lst[index_min]
        lst[index_min] = t

#Ex 6 ###
occurs = {i : 0 for i in range(0, 11)}
nums = [random.randint(0, 10) for i in range(20)]
print(nums)
for num in nums:
    occurs[num] += 1
print(occurs)

#Ex 7 ###

