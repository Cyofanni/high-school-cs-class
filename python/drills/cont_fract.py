import math

def sqrt_2_cont_fract(approx, num_calls):
    if not num_calls:
        return approx
    return 1 + (1 / (1 + sqrt_2_cont_fract(approx, num_calls - 1)))

def sqrt_2_cont_fract_iter(approx, num_iters):
    for i in range(num_iters):
        approx = 1 + (1 / (1 + approx))
    return approx

approx1 = 1
approx2 = 2
for i in range(1, 7):
    if i % 2 != 0:
        approx2 = sqrt_2_cont_fract(approx1, i)
        approx1 = sqrt_2_cont_fract(approx2, i)
    else:
        approx1 = sqrt_2_cont_fract(approx1, i)
        approx2 = sqrt_2_cont_fract(approx2, i)

    print(str(i) + '-th approximation of sqrt(2), recursively')
    print('from below', end = ' ')
    print(approx1)
    print('from above', end = ' ')
    print(approx2, end = '\n\n')

print('computed iteratively (16 iterations), starting from approx = 1: ', sqrt_2_cont_fract_iter(1, 33))
print('computed iteratively (16 iterations), starting from approx = 2: ', sqrt_2_cont_fract_iter(2, 33))

print()
print('math value: ', math.sqrt(2))
