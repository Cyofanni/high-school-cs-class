#compute L_0, L_1 ... L_n
def L_n(xs, index, x):
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
        s += ys[i] * L_n(xs, i, x)

    return s

xs = [15, 30, 45]
ys = [0.258819, 0.500000, 0.707107]
print(lagrange_polynomial_eval(xs, ys, 33))
