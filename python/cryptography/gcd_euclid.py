import sys

def gcd_euclid_iterative(a, b):
    while b != 0:
        rem = a % b
        a = b
        b = rem
    return a

def gcd_euclid_recursive(a, b):
    if b == 0:
        return a
    return gcd_euclid_recursive(b, a % b)

def gcd_euclid_recursive_ext(a, b):
    if b == 0:
        return (a, 1, 0)
    triple = gcd_euclid_recursive_ext(b, a % b)
    backward_triple = []
    backward_triple.append(triple[0])
    backward_triple.append(triple[2])
    backward_triple.append(triple[1] - a//b * triple[2])
    return backward_triple

if len(sys.argv) < 3:
    exit("not enough parameters")

a = int(sys.argv[1])
b = int(sys.argv[2])
#gcd(72, 22) = gcd(22, 6) = gcd(6, 4) = gcd(4, 2) = gcd(2, 0)

print("result of euclidean algorithm (iterative) on", a, "and", b,
      "is", gcd_euclid_iterative(a, b))
gcd = gcd_euclid_recursive(a, b)
print("result of euclidean algorithm (recursive) on", a, "and", b,
      "is", gcd)

coeffs = gcd_euclid_recursive_ext(a, b)
print("linear combination (a*x + b*y) is : ", gcd, "=", a, "*", coeffs[1], "+", b, "*", coeffs[2])
