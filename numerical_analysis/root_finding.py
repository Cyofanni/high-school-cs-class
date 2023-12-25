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

def secant_regula_falsi(f, a, b, tol, max_iters):
    x00 = a
    x0 = a
    x1 = b

    i = 1
    while i <= max_iters:
        if abs(x1 - x0) < tol:
            break
        if f(x0) * f(x1) < 0:
            m = (f(x1) - f(x0)) / (x1 - x0)
            x2 = x0 - f(x0) / m
            x00 = x0
        else:
            m = (f(x1) - f(x00)) / (x1 - x00)
            x2 = x00 - f(x00) / m

        x0 = x1
        x1 = x2
        i += 1

    return x2

def newton_raphson(f, f1, a, b, tol, max_iters):
    x0 = 0
    i = 1

    while i <= max_iters:
        m = f1(x0)
        #y - f(x0) = m * (x - x0) =>
        #y = f(x0) + m * (x - x0) =>
        #y = f(x0) + m * x - m * x0 =>
        #x = x0 - f(x0) / m
        x = x0 - f(x0) / m
        if abs(x - x0) < tol:
            break
        x0 = x
        i += 1

    return x

def f1(x):
    return x ** 3 + 2 * x ** 2 + 10 * x - 20

def f2(x):
    return x ** 3 + 4 * x - 2

def f3(x):
    return math.exp(x) + x

def f4(x):
    return x - math.cos(x)

def f5(x):
    return math.cos(x) + math.log(x)

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
print(secant(f5, 0.2, 2, 0.0001, 10))
print(secant_regula_falsi(f5, 0.2, 2, 0.0001, 10))
print()
print('newton-raphson:')
print(newton_raphson(f1, lambda x: 3*x**2 + 4*x + 10, 1, 2, 0.0001, 10))
print(newton_raphson(f2, lambda x: 3*x**2 + 4, 0, 1, 0.0001, 10))
