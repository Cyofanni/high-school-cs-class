import sys
import math

def log_(base, number, iters):
    exp = 0
    approx = 0
    exp_result = 0
    while base ** exp < number:
        approx = base ** exp
        exp += 1
        
    low_exp = exp - 1
    high_exp = exp
    exp_result = exp - 1;
    counter = 1

    while counter <= iters:
        exp_result = (low_exp + high_exp) / 2
        approx = base ** exp_result
        if approx > number:
            high_exp = exp_result 
        else:
            low_exp = exp_result
        counter += 1

    return exp_result

print('result of my logarithm function:     ',
      log_(float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3])))
print('result of python logarithm function: ',math.log2(float(sys.argv[2])))
    
