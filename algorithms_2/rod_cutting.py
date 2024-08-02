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

def cut_rod_memoized(p, n, r, s):
    if n == 0:
        return 0

    if r[n - 1] > -math.inf:
        return r[n - 1]

    q = -math.inf
    for i in range(n):
        x = cut_rod_memoized(p, n - i - 1, r, s)
        if p[i] + x > q:
            q = p[i] + x
            s[n - 1] = i + 1

    r[n - 1] = q
    return r[n - 1]

def cut_rod_bottomup(p, n):
    revenues = [0] * (n + 1)

    for i in range(1, n + 1):
        q = -math.inf
        for j in range(i):
            if p[j] + revenues[i - j - 1] > q:
                q = p[j] + revenues[i - j - 1]
        revenues[i] = q

    return revenues[len(revenues) - 1]

def print_solution(s, p, n):
    while n > 0:
        print('length: ' + str(s[n - 1]) + ', price: ' + str(p[s[n - 1] - 1]))
        n = n - s[n - 1]
    print()

prices = [1,7,7,10,13,15,20,22,25,26,30,32,33,35,40,45,50,55,100,104,105,119,120]
rod_length = len(prices)
revenues = [-math.inf] * rod_length
solution = [0] * rod_length
print(cut_rod_memoized(prices, rod_length, revenues, solution))
print_solution(solution, prices, rod_length)
print(cut_rod(prices, rod_length))
print(cut_rod_bottomup(prices, rod_length))

