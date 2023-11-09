def gauss_elim(S):
  p_row = 0
  n_rows = len(S)
  n_cols = len(S[0])

  for i in range(n_cols - 2):
    pivot = S[p_row][i]
    if pivot == 0:
      raise Exception('Zero Pivot Exception')
    for r in range(p_row + 1, n_rows):
      L = S[r][i] / pivot
      for c in range(i, n_cols):
        S[r][c] = S[r][c] - L * S[p_row][c]
    p_row += 1

system = [[6, 4, -1, 12], [-3, -1, 2, -11], [-2, 1, 2, 8]]
gauss_elim(system)
for row in system:
  print(row)
