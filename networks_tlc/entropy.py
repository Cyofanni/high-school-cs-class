import numpy as np

def information(p):
    return np.log2(1 / p)

def entropy(symbols):
    return sum([(v * information(v)) for v in symbols.values() if v != 0])

symbols = {'A':0.2,'B':0.2,'C':0.2,'D':0.2,'E':0.2}
sum_probs = sum(p for p in symbols.values())
if abs(sum_probs - 1) < 0.0001:
    print(entropy(symbols))

