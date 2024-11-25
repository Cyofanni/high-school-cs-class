def increment(bin_num):
  n = len(bin_num)
  i = 0
  while i < n and bin_num[i] == 1:
    bin_num[i] = 0
    i += 1
  if i < n:
    bin_num[i] = 1

bits = [0,0,0,0,0]
for i in range(2 ** len(bits) + 1):
  print(bits)
  increment(bits)
