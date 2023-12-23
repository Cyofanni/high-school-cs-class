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

def secant(f, a, b, tol, max_iters):
    x0 = a
    x1 = b

    #secant equation: y - f(x0) = m*(x - x0)
    #intersection secant-x: 0 - f(x0) = m*(x - x0) ->
    #-f(x0) = m*x - m*x0 -> x = x0 - f(x0)/m
    #x2 = x0 - f(x0) / m

    i = 1
    while i <= max_iters:
        if abs(x1 - x0) < tol:
            break
        m = (f(x1) - f(x0)) / (x1 - x0)
        x2 = x0 - f(x0) / m
        x0 = x1
        x1 = x2
        i += 1

    return x2

#def newton_raphson(f, f1, f2, a, b, eps, tol, max_iters):

def f1(x):
    return x ** 3 + 2 * x ** 2 + 10 * x - 20

def f2(x):
    return x ** 3 + 4 * x - 2

def f3(x):
    return math.exp(x) + x

def f4(x):
    return x - math.cos(x)

print('bisection:')
print(bisection(f1, 1, 2, 0.001, 0.001, 10))
print(bisection(f2, 0, 1, 0.001, 0.001, 10))
print(bisection(f3, -1, 0, 0.001, 0.001, 10))
print(secant(f4, 0, 1, 0.001, 10))
print()
print('secant:')
print(secant(f1, 1, 2, 0.001, 10))
print(secant(f2, 0, 1, 0.001, 10))
print(secant(f3, -1, 0, 0.001, 10))
print(secant(f4, 0, 1, 0.001, 10))
