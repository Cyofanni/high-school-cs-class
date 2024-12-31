from sympy import Function, dsolve, Derivative
from sympy.abc import t

y = Function('y')
k_m = 2
result = dsolve(Derivative(y(t), t, t) + k_m * y(t), y(t), ics = {y(0): 4,
                                                                  y(t).diff(t).subs(t, 0): 2})
print(result)

a, b = 0, 50
n = 10000
h = (b - a) / n
y0, yp0 = 4, 2
ts = [a + i * h for i in range(0, n + 1)]
yps = [yp0] +  [0] * n
ys = [y0] + [0] * n

for i in range(1, n + 1):
    yps[i] = yps[i - 1] + h * (-k_m) * ys[i - 1]
    ys[i] = ys[i - 1] + h * yps[i - 1]

print('{')
for item in zip(ts, ys):
    print(item, end = '')
    print(',')
print('}')
