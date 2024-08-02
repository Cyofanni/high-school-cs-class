#longest common subsequence
def lcs(s1, s2, i, j):
    if i == -1 or j == -1:
        return 0

    if s1[i] == s2[j]:
        return 1 + lcs(s1, s2, i - 1, j - 1)

    r1 = lcs(s1, s2, i - 1, j)
    r2 = lcs(s1, s2, i, j - 1)

    if r1 >= r2:
        return r1

    return r2
