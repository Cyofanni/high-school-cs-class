import numpy as np

def f(x):
  return np.log(x)

a, b = 0.5, 2.5
n = 100
dx = (b - a) / n

x0 = a
x1 = a + dx
x2 = a + 2 * dx
x3 = a + 3 * dx

df_dx_0 = (f(x1) - f(x0)) / dx
df_dx_1 = (f(x2) - f(x1)) / dx
df_dx_2 = (f(x3) - f(x2)) / dx

p0 = (x0, df_dx_0)
p1 = (x1, df_dx_1)
p2 = (x2, df_dx_2)
print(p0)
print(',')
print(p1)
print(',')
print(p2)

d2f_dx2_0 = (df_dx_1 - df_dx_0) / dx
d2f_dx2_1 = (df_dx_2 - df_dx_1) / dx
p3 = (x0, d2f_dx2_0)
p4 = (x1, d2f_dx2_1)
print()
print(p3)
print(',')
print(p4)

d3f_dx3_0 = (d2f_dx2_1 - d2f_dx2_0) / dx
p5 = (x0, d3f_dx3_0)
print()
print(p5)
