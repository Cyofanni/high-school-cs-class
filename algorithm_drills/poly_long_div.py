def poly_times_num(poly, num):
    return [poly[i] * num for i in range(len(poly))]

def poly_diff(poly1, poly2):
    return [poly1[i] - poly2[i] for i in range(len(poly1))]

#x^3 - 2x^2 + 0x - 4
dividend = [1, -2, 0, -4]
#x - 3
divisor = [1, -3]
partial = [1, -2]
quotient = []

for i in range(len(dividend) - len(divisor)):
    coeff_quot = partial[0] / divisor[0]
    quotient.append(coeff_quot)
    prod = poly_times_num(divisor, coeff_quot)
    partial = poly_diff(partial, prod)
    partial.pop(0)
    partial.append(dividend[i + len(divisor)])

coeff_quot = partial[0] / divisor[0]
quotient.append(coeff_quot)
prod = poly_times_num(divisor, coeff_quot)
partial = poly_diff(partial, prod)

print('dividend:', dividend)
print('divisor:', divisor)
print('quotient:', quotient)
print('remainder:', partial)
