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

def gcd_euclid_extended_recursive(a, b):
    if b == 0:
        return (a, 1, 0)
    triple = gcd_euclid_extended_recursive(b, a % b)
    return (triple[0], triple[2], triple[1] - a // b * triple[2])

def gcd_euclid_extended_iterative(a, b):
    coeffs = [(a, b)]

    while b != 0:
        rem = a % b
        a = b
        b = rem
        coeffs.append((a, b))

    triple = (a, 1, 0)
    #build the triples (d, x, y) backwards
    i = 2
    while i <= len(coeffs):
        triple = (triple[0], triple[2], triple[1] -
        coeffs[len(coeffs)-i][0] // coeffs[len(coeffs)-i][1] * triple[2])
        i += 1

    return triple


if __name__ == '__main__':
    if len(sys.argv) < 3:
        exit("not enough parameters")

    #a: 1234, b: 1789
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    #gcd(72, 22) = gcd(22, 6) = gcd(6, 4) = gcd(4, 2) = gcd(2, 0)

    print("result of euclidean algorithm (iterative) on", a, "and", b,
          "is:", gcd_euclid_iterative(a, b))
    gcd = gcd_euclid_recursive(a, b)
    '''print("result of euclidean algorithm (recursive) on", a, "and", b,
          "is:", gcd)

    coeffs = gcd_euclid_extended_recursive(a, b)
    print("linear combination (a*x + b*y), computed recursively, is:",
          gcd, "=", a, "*", coeffs[1], "+", b, "*", coeffs[2])
    '''

    coeffs = gcd_euclid_extended_iterative(a, b)
    print("linear combination (a*x + b*y), computed iteratively, is:",
          gcd, "=", a, "*", coeffs[1], "+", b, "*", coeffs[2])
    if gcd == 1:
        modular_inverse_a = coeffs[1] % b
        print("the modular inverse of " + str(a) + " (modulo " + str(b) + ") " + "is " + str(modular_inverse_a))
