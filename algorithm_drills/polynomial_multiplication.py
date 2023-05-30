#represent coefficients
poly1_3 = (6, 7, -10, 9)
poly2_3 = (-2, 0, 4, -5)
partial_products = [[0 for j in range(4)] for i in range(4)]

for i in range(len(poly2_3) - 1, -1, -1):
    for j in range(len(poly1_3) - 1, -1, -1):
        partial_products[3 - i][j] = poly2_3[i] * poly1_3[j]

for d in range(len(partial_products)):
    print(str(d + 3) + '-degree partial product: ', end = '')
    print(partial_products[d])
