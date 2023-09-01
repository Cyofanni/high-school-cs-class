def xor(p1, p2):
  res = ''
  for i in range(len(p1)):
    if p1[i] == p2[i]:
      res += '0'
    else:
      res += '1'
  return res

#return true if p1 divides p2
def divides(p1, p2):
  return len(p1) <= len(p2) and p2[0] == '1'

def crc(P, G):
  Q = []
  P_l = len(P)
  G_l = len(G)
  w_end = G_l - 1
  partial = P[0:w_end + 1]
  print('partials')

  while w_end < P_l - 1:
    print(partial)
    w_end += 1
    if divides(G, partial):
      Q.append(1)
      partial = xor(G, partial) + P[w_end]
      partial = partial.removeprefix('0')
    else:
      Q.append(0)
      partial = xor('0' * len(G), partial) + P[w_end]
      partial = partial.removeprefix('0')

  if divides(G, partial):
    Q.append(1)
    partial = xor(G, partial)
  else:
    Q.append(0)
    partial = xor('0' * len(G), partial)

  return {'Q(x)':Q, 'R(x)':partial}


P = '11010111110000'
G = '10011'
P1 = '101110000'
G1 = '1001'
print(crc(P1, G1))
