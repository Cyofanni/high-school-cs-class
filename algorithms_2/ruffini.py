A = [3, 6, -8, 1, -9]
B = [1, -4]

Q_R = []
curr_coeff = A[0]
Q_R.append(curr_coeff)

i = 0
while i <= len(A) - 2:
  curr_coeff = Q_R[i] * (-B[1])
  Q_R.append(A[i + 1] + curr_coeff)
  i += 1

print(Q_R)
