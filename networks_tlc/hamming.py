m = [None, 1, 0, 0, 0 ,0, 0, 1]
n_chk_bits = 4
cw_len = len(m) - 1 + n_chk_bits
codeword = [0 for i in range(cw_len)]
codeword.insert(0, None)
codeword[3] = 1
codeword[5] = 0
codeword[6] = 0
codeword[7] = 0
codeword[9] = 0
codeword[10] = 0
codeword[11] = 1

pos = [i for i in range(1, cw_len + 1)]

f1 = filter(lambda x: x & 0b1 == 1, pos)
p1 = list(f1)
f2 = filter(lambda x: x & 0b10 == 2, pos)
p2 = list(f2)
f3 = filter(lambda x: x & 0b100 == 4, pos)
p3 = list(f3)
f4 = filter(lambda x: x & 0b1000 == 8, pos)
p4 = list(f4)

print(codeword)

for ind in p1:
    print(ind)
    codeword[1] = codeword[1] + codeword[ind]
codeword[1] = codeword[1] % 2

for ind in p2:
    codeword[2] = codeword[2] + codeword[ind]
codeword[2] = codeword[2] % 2

for ind in p3:
    codeword[4] = codeword[4] + codeword[ind]
codeword[4] = codeword[4] % 2

for ind in p4:
    codeword[8] = codeword[8] + codeword[ind]
codeword[8] = codeword[8] % 2

print(codeword)
