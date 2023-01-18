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

if len(sys.argv) < 3:
    exit("not enough parameters")

a = int(sys.argv[1])
b = int(sys.argv[2])
#gcd(72, 22) = gcd(22, 6) = gcd(6, 4) = gcd(4, 2) = gcd(2, 0)
print("result of euclidean algorithm (iterative) on", a, "and", b,
      "is", gcd_euclid_iterative(a, b))
print("result of euclidean algorithm (recursive) on", a, "and", b,
      "is", gcd_euclid_recursive(a, b))
