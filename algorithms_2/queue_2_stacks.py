def enqueue(s1, s2, item):
  s2.append(item)

def dequeue(s1, s2):
  if len(s2) == 0:
    return
  s1 = s2.copy()
  s1.reverse()
  s1.pop()
  s1.reverse()
  for i in range(len(s1)):
    s2[i] = s1[i]
  s2.pop()

st1 = []
st2 = []
enqueue(st1, st2, 3)
print(st2)
enqueue(st1, st2, 76)
print(st2)
enqueue(st1, st2, 35)
print(st2)
enqueue(st1, st2, 71)
print(st2)
enqueue(st1, st2, 1)
print(st2)

dequeue(st1, st2)
print(st2)
dequeue(st1, st2)
print(st2)
dequeue(st1, st2)
print(st2)
dequeue(st1, st2)
print(st2)
dequeue(st1, st2)
print(st2)
dequeue(st1, st2)
print(st2)
