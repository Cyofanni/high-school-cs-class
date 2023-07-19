def eval_coeff_repr(coeffs, x0):
  val = 0
  e = 0
  for c in coeffs:
    val += c * x0 ** e
    e += 1
  return val

def eval_horner_rec(coeffs, x0):
  if len(coeffs) == 0:
    return 0
  return coeffs[0] + x0 * eval_horner_rec(coeffs[1:len(coeffs)], x0)

def eval_horner_iter(coeffs, x0):
  b = coeffs[len(coeffs) - 1]
  for i in range(len(coeffs) - 2, -1, -1):
    b = coeffs[i] + x0 * b
  return b

#9x^3 + 4x^2 - 5x + 1
poly = [1, -5, 4, 9]
print(eval_coeff_repr(poly, 3))
print(eval_horner_rec(poly, 3))
print(eval_horner_iter(poly, 3))
