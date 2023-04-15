import math

def sqrt_2_cont_fract(approx, num_calls):
    if not num_calls:
        return approx
    return 1 + (1 / (1 + sqrt_2_cont_fract(approx, num_calls - 1)))


for i in range(1, 33):
    print(str(i) + '-th approximation of sqrt(2)')
    print('from below', end = ' ')
    print(sqrt_2_cont_fract(1, i))
    print('from above', end = ' ')
    print(sqrt_2_cont_fract(2, i), end = '\n\n')

print('math value: ', math.sqrt(2))
