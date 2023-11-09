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

def secant(f, f2, a, b, eps, tol, max_iters):

def regula_falsi(f, f2, a, b, eps, tol, max_iters):

def newton_raphson(f, f1, f2, a, b, eps, tol, max_iters):

def f1(x):
    return x ** 3 + 2 * x ** 2 + 10 * x - 20

def f2(x):
    return x ** 3 + 4 * x - 2

def f2_der_2(x):
    return 6 * x

def f3(x):
    return math.exp(x) + x

print('bisection:')
print(bisection(f1, 1, 2, 0.001, 0.001, 20))
print(bisection(f2, 0, 1, 0.001, 0.001, 20))
print(bisection(f3, -1, 0, 0.001, 0.001, 20))
print('secant:')
#print(secant(f1, 1, 2, 0.001, 0.001, 10))
print(secant(f2, f2_der_2, 0, 1, 0.001, 0.001, 10))
#print(secant(f3, -1, 0, 0.001, 0.001, 10))

