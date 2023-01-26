import math

def sqrt_bisection(n, precision):
    interval_low = 0;
    interval_high = n;
    found_exact = False
    previous_approximation = 1
    approximation = 0

    while abs(previous_approximation - approximation) > precision \
        and found_exact == False:

        previous_approximation = approximation
        approximation = (interval_low + interval_high) / 2
        if approximation ** 2 > n:
            interval_high = approximation
        elif approximation ** 2 < n:
            interval_low = approximation
        else:
            found_exact == True

    return approximation

print("my sqrt:     ", sqrt_bisection(260, 0.00000001))
print("python sqrt: ", math.sqrt(260))
