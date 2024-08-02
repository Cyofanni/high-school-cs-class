import math

def cut_rod(p, n):
    if n == 0:
        return 0

    q = -math.inf

    for i in range(n):
        x = p[i] + cut_rod(p, n - i - 1)
        if x > q:
            q = x

    return q

def cut_rod_memoized(p, n, r):
    if n == 0:
        return 0

    if r[n - 1] > -math.inf:
        return r[n - 1]

    q = -math.inf
    for i in range(n):
        x = cut_rod_memoized(p, n - i - 1, r)
        if p[i] + x > q:
            q = p[i] + x

    r[n - 1] = q
    return q

def cut_rod_bottomup(p, n):
    revenues = [0] * (n + 1)

    for i in range(1, n + 1):
        q = -math.inf
        for j in range(i):
            if p[j] + revenues[i - j - 1] > q:
                q = p[j] + revenues[i - j - 1]
        revenues[i] = q

    return revenues[len(revenues) - 1]

prices = [6, 7, 8, 9, 12, 13, 16, 17, 18, 20, 24, 30]
rod_length = len(prices)
revenues = [-math.inf] * rod_length
print(cut_rod_memoized(prices, rod_length, revenues))
print(cut_rod(prices, rod_length))
print(cut_rod_bottomup(prices, rod_length))
