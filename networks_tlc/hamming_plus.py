def get_r(m):
    r = m
    while m + r + 1 <= 2 ** r:
        r -= 1
    return r + 1

def hamming(m_bits):
    m = len(m_bits) - 1
    r = get_r(m)
    codeword = m_bits.copy()
    i, inc = 1, 1
    while i < m + r:
        codeword.insert(i, 0)
        i += inc
        inc *= 2

    i, inc = 1, 1
    while i < m + r + 1:
        for j in range(i, m + r + 1):
            if j & inc == inc:
                codeword[i] ^= codeword[j]
        i += inc
        inc *= 2

    return codeword[1:]

cw = hamming([None,1,0,0,0,0,0,1])
print(cw)
print(len(cw))
