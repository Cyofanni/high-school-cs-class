import math

#eval polynomial at x
def L_n_eval(xs, index, x):
    prod_num = 1
    prod_den = 1
    for i in range(len(xs)):
        if i != index:
            prod_num = prod_num * (x - xs[i])
            prod_den = prod_den * (xs[index] - xs[i])

    return prod_num / prod_den

#build polynomial as a string
def L_n_build(xs, index):
    poly_num = ''
    poly_den = ''
    for i in range(len(xs)):
        if i != index:
            poly_num += '(x - ' + str(xs[i]) + ')'
            poly_den += '(' + str(xs[index]) + ' - ' + str(xs[i]) + ')'

    return '(' + '(' + poly_num + ')' + '/' + '(' + poly_den + ')' + ')'

#eval polynomial at x
def lagrange_polynomial_eval(xs, ys, x):
    s = 0
    for i in range(len(ys)):
        s += ys[i] * L_n_eval(xs, i, x)

    return s

#build polynomial as a string
def lagrange_polynomial_build(xs, ys):
    poly = ''
    for i in range(len(ys)):
        poly += str(ys[i]) + L_n_build(xs, i)
        if i < len(ys) - 1:
            poly += ' + '

    return poly

print("f(x) = sin(x)")
xs = [15, 30, 45]
ys = [0.258819, 0.500000, 0.707107]
print(L_n_build(xs, 0))
print(L_n_build(xs, 1))
print(L_n_build(xs, 2))
print(lagrange_polynomial_build(xs, ys))
print(lagrange_polynomial_eval(xs, ys, 33))
print(math.sin(math.radians(33)))

print()
print("f(x) = 2 ** x")
xs = [0, 1, 2, 3, 4, 5, 6]
ys = [1, 2, 4, 8, 16, 32, 64]
print(lagrange_polynomial_build(xs, ys))
print(lagrange_polynomial_eval(xs, ys, 5.57))
print(2 ** 5.57)
