def permutations(A, curr_permut, taken_inds):
    if len(taken_inds) == len(A):
        print(curr_permut)
        return 1
    count = 0
    for k in range(len(A)):
        if k not in taken_inds:
            count = count + permutations(A, curr_permut + A[k], taken_inds + [k])
    return count

print('enter a string: ')
L = input()
n = permutations(L, '', [])
print(n)
