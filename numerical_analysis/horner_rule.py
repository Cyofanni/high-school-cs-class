def horner_rule_eval_rec(poly_coeffs, x):
    if len(poly_coeffs) == 0:
        return 0
    return poly_coeffs[0] + x * horner_rule_eval_rec(poly_coeffs[1:], x)

def horner_rule_eval_iter(poly_coeffs, x):
    value = poly_coeffs[len(poly_coeffs) - 1]
    for i in range(len(poly_coeffs) - 2, -1, -1):
        value = value * x + poly_coeffs[i]

    return value

def horner_rule_print(poly_coeffs):
    if len(poly_coeffs) == 1:
        print(poly_coeffs[0], end = '')
        return
    print(poly_coeffs[0], end = ' + x(')
    horner_rule_print(poly_coeffs[1:])
    print(')', end = '')


poly = [-2, 6, 3, 1, 7]
horner_rule_print(poly)
print()
print(horner_rule_eval_rec(poly, 8))
print(horner_rule_eval_iter(poly, 8))
print()
poly = [2, -4, 5, -7]
horner_rule_print(poly)
print()
print(horner_rule_eval_rec(poly, 9))
print(horner_rule_eval_iter(poly, 9))
print()
