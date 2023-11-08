import math

def bisection(f, a, b, eps, tol, max_iters):
    i = 1
    while i <= max_iters:
        p = (a + b) / 2
        if abs(f(p)) < eps or abs(b - a) < tol:
            break
        if f(a) * f(p) > 0:
            a = p
        else:
            b = p
        i = i + 1

    return p

def secant(f, a, b, eps, tol, max_iters):
    x_0 = a - (f(a) * (b - a)) / (f(b) - f(a))
    i = 1
    while i <= max_iters:
        x_1 = x_0 - (f(x_0) * (b - x_0)) / (f(b) - f(x_0))
        if abs(f(x_1)) < eps or abs(x_1 - x_0) < tol:
            break
        x_0 = x_1
        i += 1

    return x_1

def f1(x):
    return x ** 3 + 2 * x ** 2 + 10 * x - 20

def f2(x):
    return x ** 3 + 4 * x - 2

def f3(x):
    return math.exp(x) + x

print(bisection(f1, 1, 2, 0.001, 0.001, 20))
print(bisection(f2, 0, 1, 0.001, 0.001, 20))
print(bisection(f3, -1, 0, 0.001, 0.001, 20))

print(secant(f1, 1, 2, 0.001, 0.001, 10))
print(secant(f2, 0, 1, 0.001, 0.001, 10))
print(secant(f3, -1, 0, 0.001, 0.001, 10))
