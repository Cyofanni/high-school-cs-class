num_rows = 10
num_cols = num_rows * 2 - 1

pascal_matrix = [[0 for c in range(num_cols)] for r in range(num_rows)]
pascal_matrix[0][num_cols // 2] = 1

index_first = num_cols // 2 - 1
for r in range(1, num_rows):
    for c in range(index_first, num_cols, 2):
        if c in range(1, num_cols - 1):
            pascal_matrix[r][c] = pascal_matrix[r - 1][c - 1] + pascal_matrix[r - 1][c + 1]
        elif c == 0:
            pascal_matrix[r][c] = pascal_matrix[r - 1][c + 1]
        elif c == num_cols - 1:
            pascal_matrix[r][c] = pascal_matrix[r - 1][c - 1]

    index_first -= 1

for row in pascal_matrix:
    for num in row:
        if num == 0:
            print('   ', end = '')
        else:
            print(num, end = '  ')
    print()
