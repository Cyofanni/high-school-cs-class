import math

def longest_palindrome(s, i, j):
    if i > j:
        return 0
    if i == j:
        return 1
    if s[i] == s[j]:
        return 2 + longest_palindrome(s, i + 1, j - 1)
    sub_prob_1 = longest_palindrome(s, i, j - 1)
    sub_prob_2 = longest_palindrome(s, i + 1, j)
    sub_prob_3 = longest_palindrome(s, i + 1, j - 1)
    return max(sub_prob_1, sub_prob_2, sub_prob_3)

def longest_palindrome_memoized(s, i, j, lookup):
    if i > j:
        return 0
    if i == j:
        return 1
    if lookup[i][j] > -math.inf:
        return lookup[i][j]

    if s[i] == s[j]:
        lookup[i][j] = 2 + longest_palindrome_memoized(s, i + 1, j - 1, lookup)
        return lookup[i][j]

    lookup[i][j - 1] = longest_palindrome_memoized(s, i, j - 1, lookup)
    lookup[i + 1][j] = longest_palindrome_memoized(s, i + 1, j, lookup)
    lookup[i + 1][j - 1] = longest_palindrome_memoized(s, i + 1, j - 1, lookup)
    lookup[i][j] = max(lookup[i][j - 1], lookup[i + 1][j], lookup[i + 1][j - 1])
    return lookup[i][j]

st = 'xycqyoaibohphobi'
lookup = [[-math.inf] * len(st) for _ in range(len(st))]
print(longest_palindrome_memoized(st, 0, len(st) - 1, lookup))
lookup = [[-math.inf] * len(st) for _ in range(len(st))]
print(longest_palindrome(st, 0, len(st) - 1))
