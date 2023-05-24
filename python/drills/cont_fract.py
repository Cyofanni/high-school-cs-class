import math

def sqrt2_cont_fract_r(approx, num_calls):
    if not num_calls:
        return approx
    return 1 + (1 / (1 + sqrt2_cont_fract_r(approx, num_calls - 1)))

def sqrt2_cont_fract_i(approx, num_iters):
    for i in range(num_iters):
        approx = 1 + (1 / (1 + approx))
    return approx

print(sqrt2_cont_fract_r(1, 24))
print(sqrt2_cont_fract_i(1, 24))
print(math.sqrt(2))
