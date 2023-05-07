def z_rec(num_calls, c):
    if num_calls == 0:
        return 0
    return z_rec(num_calls - 1, c) ** 2 + c

def z_iter(num_iters, c):
    z = 0
    for i in range(num_iters):
        z = z ** 2 + c
    return z

#c: 1 --> tends to infinity
#c: -1 --> bounded
c = 1
for n in range(12):
    print(z_rec(n, c))
    print()
    assert(z_rec(0, c) == z_iter(0, c))
