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

prices = [2, 5, 6]
print(cut_rod(prices, len(prices)))

