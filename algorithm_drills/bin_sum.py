def bin_sum(bin1, bin2):
  size = len(bin1)
  res = []
  carry = False
  for i in range(size - 1, -1, -1):
    if bin1[i] == 0 and bin2[i] == 0:
      if carry == False:
        res.insert(0, 0)
      else:
        res.insert(0, 1)
        carry = False
    elif bin1[i] == 0 and bin2[i] == 1:
      if carry == False:
        res.insert(0, 1)
      else:
        res.insert(0, 0)
    elif bin1[i] == 1 and bin2[i] == 0:
      if carry == False:
        res.insert(0, 1)
      else:
        res.insert(0, 0)
    else:
      if carry == False:
        res.insert(0, 0)
        carry = True
      else:
        res.insert(0, 1)

  if carry == True:
    res.insert(0, 1)

  return res

print(bin_sum([1, 1, 1, 1, 0, 1], [0, 0, 1, 1, 0, 1]))
