import time

#reverse a string, recursively
def revseq(seq):
    if len(seq) == 0:
        return ''
    return seq[len(seq)-1] + revseq(seq[0:(len(seq)-1)])

#factorial, tail recursive, iterative, and head recursive
def factorial_tail_rec(num, acc):
    if num == 0:
        return acc
    acc = acc * num
    return factorial_tail_rec(num - 1, acc)

def factorial_iterative(num):
    acc = 1
    for i in range(2, num):
        acc = acc * i
    return acc

def factorial_head_recursive(num):
    if num == 0:
        return 1
    return num * factorial_head_recursive(num - 1)

def insert_into_sorted_list(lst, item):
    i = 0
    while i < len(lst) and lst[i] < item:
        i += 1
    lst.insert(i, item)

#test revseq
composers = ['bach', 'mozart', 'beethoven', 'vivaldi', 'scarlatti']
for composer in composers:
    print(revseq(composer))

#test factorials
start_time = time.time()
for i in range(40):
    print(factorial_tail_rec(i, 1))
end_time = time.time()
print(end_time - start_time)

print()
print()

start_time = time.time()
for i in range(40):
    print(factorial_iterative(i))
end_time = time.time()
print(end_time - start_time)

print()
print()

start_time = time.time()
for i in range(100):
    print(factorial_head_recursive(i))
end_time = time.time()
print(end_time - start_time)

print()
print()
#test insert_into_sorted_list
items = [8, 6, 5, 67, 123]
insert_into_sorted_list(items, 124)
print(items)
