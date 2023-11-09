# 4x - 2y + z = 9
# 2x + 5y = -3
# x + y - 3z = -9

def f_x0(x1, x2):
  return 9/4 - (-2*x1 + x2) / 4

def f_x1(x0, x2):
  return -3 / 5 - 2*x0 / 5

def f_x2(x0, x1):
  return 3 - (x0 + x1) / -3

max_iters = 10
tol = 0.00001
x0_k_1 = 0
x1_k_1 = 0
x2_k_1 = 0
i = 1
while i <= max_iters:
  x0_k = f_x0(x1_k_1, x2_k_1)
  x1_k = f_x1(x0_k_1, x2_k_1)
  x2_k = f_x2(x0_k_1, x1_k_1)
  if abs(x0_k - x0_k_1) < tol and abs(x1_k - x1_k_1) < tol and (x2_k - x2_k_2) < tol:
    break
  x0_k_1 = x0_k
  x1_k_1 = x1_k
  x2_k_1 = x2_k
  i += 1

print('x0:', str(x0_k))
print('x1:', str(x1_k))
print('x2:', str(x2_k))
