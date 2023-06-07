x = 1
y = 1
total = 5

while x <= total - 2:
  y = 1
  while y < total - x:
    z = total - y - x
    print(x, y, z)
    y += 1
  x += 1
