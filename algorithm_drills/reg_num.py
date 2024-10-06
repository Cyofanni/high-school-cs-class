def gen_reg_num(n, n_call):
  if (n_call == n):
    return
  print(n_call * '0', end = '')
  print(n_call * '1', end = '')
  gen_reg_num(n, n_call + 1)

gen_reg_num(6, 1)
print()
