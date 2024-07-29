def conv_2_dec(s, i, j):
    if j == i - 1:
        return
    if j == i:
        return int(s[j])
    return int(s[j]) + 10 * conv_2_dec(s, i, j - 1)

def match(t, p, i):
    p_l = len(p)
    count = 0
    for p_c, t_c in zip(p, t[i : i + p_l]):
        if p_c == t_c:
            count += 1
    if count == p_l:
        return True

    return False

def rabin_karp(text, pattern, q):
    t_l, p_l = len(text), len(pattern)
    t_num = conv_2_dec(text, 0, p_l - 1)
    p_num = conv_2_dec(pattern, 0, p_l - 1)
    shifts = []

    if p_num % q == t_num % q:
        print('congruent', i)
        if match(text, pattern, 0):
            shifts.append(0)

    for i in range(1, t_l - p_l + 1):
        t_num = t_num - int(text[i - 1]) * 10 ** (p_l - 1)
        t_num *= 10
        t_num += int(text[i + p_l - 1])
        if p_num % q == t_num % q:
            print('congruent', i)
            if match(text, pattern, i):
                shifts.append(i)

    return shifts

text = '2359023141526739921331488069553141556431415'
pattern = '31415'
r = rabin_karp(text, pattern, 13)
print(r)
