import math

def sqrt_cont_fract_rec(n, n_calls):
    if n_calls == 0:
        return 0
    return 1 + (n - 1) / (sqrt_cont_fract_rec(n, n_calls - 1) + 1)

def sqrt_cont_fract_iter(n, max_iters):
    approx = 0
    for i in range(max_iters):
        approx = 1 + (n - 1) / (1 + approx)

    return approx

n = 2
print(sqrt_cont_fract_rec(n, 150))
print(sqrt_cont_fract_iter(n, 150))
print(math.sqrt(n))
