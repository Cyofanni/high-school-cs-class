fib_memoiz = {}

def fibonacci(n):
    if n == 0 or n == 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

def fibonacci_dp(n):
    if n == 0:
        fib_memoiz[0] = 0
        return 0
    if n == 1:
        fib_memoiz[1] = 1
        return 1
    if n in fib_memoiz.keys():
        f = fib_memoiz[n]
    else:
        fib_memoiz[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2)
        f = fib_memoiz[n]

    return f

n = 60
print(fibonacci_dp(n))
print(fibonacci(n))
