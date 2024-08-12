def edit_distance(s1, s2, i, j):
    if i == len(s1):
        return 0.5 * len(s2[j:])
    if j == len(s2):
        return 0.5 * len(s1[i:])
    if s1[i] == s2[j]:
        return edit_distance(s1, s2, i + 1, j + 1)
    #deletion
    c1 = 0.5 + edit_distance(s1, s2, i + 1, j)
    #insertion
    c2 = 0.5 + edit_distance(s1, s2, i, j + 1)
    #substitution
    c3 = 1 + edit_distance(s1, s2, i + 1, j + 1)
    return min(c1, c2, c3)

st1 = 'semprecahpeo'
st2 = 'semprecaro'
print(edit_distance(st1, st2, 0, 0))
