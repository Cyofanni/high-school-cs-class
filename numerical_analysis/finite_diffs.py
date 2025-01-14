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
x4 = a + 4 * dx
x5 = a + 5 * dx

df_dx_0 = (f(x1) - f(x0)) / dx
df_dx_1 = (f(x2) - f(x1)) / dx
df_dx_2 = (f(x3) - f(x2)) / dx
df_dx_3 = (f(x4) - f(x3)) / dx
df_dx_4 = (f(x5) - f(x4)) / dx

p0 = (x0, df_dx_0)
p1 = (x1, df_dx_1)
p2 = (x2, df_dx_2)
p3 = (x3, df_dx_3)
p4 = (x4, df_dx_4)
print(p0)
print(',')
print(p1)
print(',')
print(p2)
print(',')
print(p3)
print(',')
print(p4)

d2f_dx2_0 = (df_dx_1 - df_dx_0) / dx
d2f_dx2_1 = (df_dx_2 - df_dx_1) / dx
d2f_dx2_2 = (df_dx_3 - df_dx_2) / dx
d2f_dx2_3 = (df_dx_4 - df_dx_3) / dx
p5 = (x0, d2f_dx2_0)
p6 = (x1, d2f_dx2_1)
p7 = (x2, d2f_dx2_2)
p8 = (x3, d2f_dx2_3)
print('\n\n')
print(p5)
print(',')
print(p6)
print(',')
print(p7)
print(',')
print(p8)

d3f_dx3_0 = (d2f_dx2_1 - d2f_dx2_0) / dx
d3f_dx3_1 = (d2f_dx2_2 - d2f_dx2_1) / dx
d3f_dx3_2 = (d2f_dx2_3 - d2f_dx2_2) / dx
p8 = (x0, d3f_dx3_0)
p9 = (x1, d3f_dx3_1)
p10 = (x2, d3f_dx3_2)
print('\n\n')
print(p8)
print(',')
print(p9)
print(',')
print(p10)
