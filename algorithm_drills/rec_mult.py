def mult(a, b):
  if a == 0:
    return 0
  if a % 2 == 0:
    return mult((a // 2), 2 * b)
  return mult(a - 1, b) + b

while True:
  p = int(input('enter a natural number: '))
  q = int(input('enter a natural number: '))
  print('their product is:' , mult(p, q))
  print('their product is:' , p * q)
  print()
