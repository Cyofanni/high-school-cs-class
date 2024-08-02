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

def lcs_bottomup(s1, s2):
    m, n = len(s1), len(s2)
    C = [[0] * (n + 1) for _ in range(m + 1)]
    B = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                C[i][j] = 1 + C[i - 1][j - 1]
                B[i][j] = 'D'
            else:
                if C[i - 1][j] >= C[i][j - 1]:
                    C[i][j] = C[i - 1][j]
                    B[i][j] = 'N'
                else:
                    C[i][j] = C[i][j - 1]
                    B[i][j] = 'W'

    return C, B

def compute_lcs(s1, s2, B):
    B_rows, B_cols = len(B), len(B[0])
    lcs = []
    i, j = B_rows - 1, B_cols - 1
    while i > 0 and j > 0:
        if B[i][j] == 'D':
            lcs.insert(0, s1[i - 1])
            i -= 1
            j -= 1
        elif B[i][j] == 'N':
            i -= 1
        elif B[i][j] == 'W':
            j -= 1

    return lcs

st1 = 'ABCBDAB'
st2 = 'BDCABA'
C, B = lcs_bottomup(st1, st2)
print(C[len(C) - 1][len(C[0]) - 1])
for row in B:
    print(row)
res = compute_lcs(st1, st2, B)
print(res)
