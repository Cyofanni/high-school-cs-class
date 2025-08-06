def print_vno(n):
  if n == 0:
    print('0', end = '')
    return
  print('{', end = '')
  for i in range(0, n):
    print_vno(i)
    if i < n - 1:
      print(',', end = '')
  print('}', end = '')

for k in range(6):
  print_vno(k)
  print()
