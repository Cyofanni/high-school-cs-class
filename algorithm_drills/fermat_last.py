#verify Fermat's Last Theorem

n = 3  #set n = 2 to generate pythagorean triples
       #no triple will be found for n > 2
total = 3

while total < 1024:
  x = 1
  y = 1
  while x <= total - 2:
    y = 1
    while y < total - x:
      z = total - y - x
      if x ** n + y ** n == z ** n:
        print('found triple:', x, y, z)
      y += 1
    x += 1
  total += 1
