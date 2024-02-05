import random

def is_sorted(v):
  for i in range(len(v) - 1):
    if v[i] > v[i + 1]:
      return False

  return True

def bogo_sort(v):
  while not is_sorted(v):
    i = random.randint(0, len(v) - 1)
    j = random.randint(0, len(v) - 1)
    t = v[i]
    v[i] = v[j]
    v[j] = t
    print(v)

ar = [4, 1, 1, 9, 1, 5, 3, 9, 8, 6, -4]
bogo_sort(ar)
print(ar)
