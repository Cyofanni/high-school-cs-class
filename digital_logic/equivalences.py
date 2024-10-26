def f1(a, b, c):
  return (a and b) or int(not(c)) or (a and int(not(c)))

def f1_red(a, b, c):
 return (a and b) or int(not(c))

print(f1(0,0,0) == f1_red(0,0,0))
print(f1(0,0,1) == f1_red(0,0,1))
print(f1(0,1,0) == f1_red(0,1,0))
print(f1(0,1,1) == f1_red(0,1,1))
print(f1(1,0,0) == f1_red(1,0,0))
print(f1(1,0,1) == f1_red(1,0,1))
print(f1(1,1,0) == f1_red(1,1,0))
print(f1(1,1,1) == f1_red(1,1,1))
