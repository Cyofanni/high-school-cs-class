import sys

def place_queen(cb, i, j):
    cb[i][j] = 'Q'

def erase_queen(cb, i, j):
    cb[i][j] = '-'

def print_board(cb):
    for row in cb:
        for cell in row:
            print(cell, end = ' ')
        print()

def find_conflict(cb, i, j):
    side = len(cb)

    #backwards on column j
    for k in range(i - 1, -1, -1):
        if cb[k][j] == 'Q':
            return True

    #backwards-leftwards
    row_ind = i - 1
    k = j - 1
    while row_ind >= 0 and k >= 0:
        if cb[row_ind][k] == 'Q':
            return True
        row_ind = row_ind - 1
        k = k - 1

    #backwards-rightwards
    row_ind = i - 1
    k = j + 1
    while row_ind >= 0 and k <= side - 1:
        if cb[row_ind][k] == 'Q':
            return True
        row_ind = row_ind - 1
        k = k + 1

    return False

def solve_n_queens(cb, row):
    if row == len(cb):
        print_board(cb)
        print()
        return 1

    num_sols = 0
    col = 0
    while col <= len(cb) - 1:
        if find_conflict(cb, row, col) == False:
            place_queen(cb, row, col)
            num_sols = num_sols + solve_n_queens(cb, row + 1)
            erase_queen(cb, row, col)
        col += 1

    return num_sols

side = int(sys.argv[1])
chessboard = [['-' for j in range(side)] for i in range(side)]
print(solve_n_queens(chessboard, 0))
