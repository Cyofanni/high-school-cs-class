def place_queen(cb, i, j):
    cb[i][j] = '*'

def erase_queen(cb, i, j):
    cb[i][j] = '-'

def find_conflict(cb, side, i, j):
    found_conflict = False
    #backwards
    for k in range(i - 1, -1, -1):
        if cb[k][j] == '*':
            found_conflict = True
            break

    #backwards-leftwards
    if found_conflict == False:
        row_ind = i - 1
        for k in range(j - 1, -1, -1):
            if cb[row_ind][k] == '*':
                found_conflict = True
                break
            row_ind = row_ind - 1

    #backwards-rightwards
    if found_conflict == False:
        row_ind = i - 1
        for k in range(j + 1, side):
            if cb[row_ind][k] == '*':
                found_conflict = True
                break
            row_ind = row_ind - 1

    return found_conflict

def solve_n_queens(cb, side, row):
    if row == side:
        for row in cb:
            for cell in row:
                print(cell, end = ' ')
            print()
        print()
        return 1

    num_sols = 0
    col = 0
    while col <= side - 1:
        if find_conflict(cb, side, row, col) == False:
            place_queen(cb, row, col)
            num_sols = num_sols + solve_n_queens(cb, side, row + 1)
            erase_queen(cb, row, col)
        col += 1

    return num_sols

side = 5
chessboard = [['-' for j in range(side)] for i in range(side)]
print(solve_n_queens(chessboard, side, 0))
