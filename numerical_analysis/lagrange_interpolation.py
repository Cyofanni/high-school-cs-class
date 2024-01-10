import math

#compute L_0, L_1 ... L_n
def L_n_eval(xs, index, x):
    prod_num = 1
    prod_den = 1
    for i in range(len(xs)):
        if i != index:
            prod_num = prod_num * (x - xs[i])
            prod_den = prod_den * (xs[index] - xs[i])

    return prod_num / prod_den

def lagrange_polynomial_eval(xs, ys, x):
    s = 0
    for i in range(len(ys)):
        s += ys[i] * L_n_eval(xs, i, x)

    return s


print("f(x) = sin(x)")
xs = [15, 30, 45]
ys = [0.258819, 0.500000, 0.707107]
print(lagrange_polynomial_eval(xs, ys, 33))
print(math.sin(math.radians(33)))

print()
print("f(x) = 2 ** x")
xs = [0, 1, 2, 3, 4, 5]
ys = [1, 2, 4, 8, 16, 32]
print(lagrange_polynomial_eval(xs, ys, 0.2523))
print(2 ** 0.2523)
