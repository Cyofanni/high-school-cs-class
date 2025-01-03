import sys

def f_f1_ratio(base, step, num_pts):
    fx = [base ** (i * step) for i in range(num_pts)]
    f1_x = [(fx[i] - fx[i - 1]) / step for i in range(1, len(fx))]
    return [item[0] / item[1] for item in zip(f1_x, fx)]

step = .1e-6
base = float(sys.argv[1])
ratios = f_f1_ratio(base, step, 10)
for r in ratios:
    print(r)
