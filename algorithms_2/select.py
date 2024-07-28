def partition(A, low, high):
    i = low - 1
    pivot = A[high]
    for j in range(low, high + 1):
        if A[j] <= pivot:
            i = i + 1
            A[i], A[j] = A[j], A[i]

    return i

def select(A, l, h, i):
    print(l, h)
    if l == h:
        return A[l]

    q = partition(A, l, h)
    print(A)
    print()

    k = q - l + 1

    if i == k - 1:
        return A[q]

    if i < k - 1:
        return select(A, l, q - 1, i)

    return select(A, q + 1, h, i - k)


r = 7
nums = [304, 20, 13115, 152, -10, 14, 7, 403, 2, -1, 20]
print(sorted(nums)[r])
print()
print(nums)
print()
x = select(nums, 0, len(nums) - 1, r)
print(x)

'''
nums_1 = nums.copy()

for r in range(len(nums)):
    print(sorted(nums)[r])
    print(nums)
    print(select(nums, 0, len(nums) - 1, r))
    nums = nums_1.copy()
    print()
'''
