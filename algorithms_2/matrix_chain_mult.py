import math

def matrix_chain_mult(sizes, i, j):
    if i == j:
        return 0

    res = math.inf
    for k in range(i, j):
        s1 = matrix_chain_mult(sizes, i, k) + \
            matrix_chain_mult(sizes, k + 1, j) + \
            sizes[i][0] * sizes[k][1] * sizes[j][1]
        if s1 < res:
            res = s1

    return res

sizes = [(30,35),(35,15),(15,5),(5,10),(10,20),(20,25)]
print(matrix_chain_mult(sizes, 0, len(sizes) - 1))
