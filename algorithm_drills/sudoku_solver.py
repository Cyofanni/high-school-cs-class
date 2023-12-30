def print_board(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end = '')
            if j % 3 == 2:
                print('  ', end = '')
            else:
                print(' ', end = '')
        if i % 3 == 2:
            print('\n')
        else:
            print()

def get_block_start(row, col):
    grid_num = (row // 3) * 3 + col // 3
    if grid_num == 0:
        return (0, 0)
    elif grid_num == 1:
        return (0, 3)
    elif grid_num == 2:
        return (0, 6)
    elif grid_num == 3:
        return (3, 0)
    elif grid_num == 4:
        return (3, 3)
    elif grid_num == 5:
        return (3, 6)
    elif grid_num == 6:
        return (6, 0)
    elif grid_num == 7:
        return (6, 3)
    elif grid_num == 8:
        return (6, 6)
    else:
        return (-1, -1)

#brute-force algorithm
def no_dup(board, num, row, col):
    #check row
    for j in range(9):
        if j != col and board[row][j] == num:
            return False
    #check column
    for j in range(9):
        if j != row and board[j][col] == num:
            return False
    #check block
    block_start_row = get_block_start(row, col)[0]
    block_start_col = get_block_start(row, col)[1]
    for i in range(block_start_row, block_start_row + 3):
        for j in range(block_start_col, block_start_col + 3):
            if i != row and j != col and board[i][j] == num:
                return False

    return True

def solve(board, row, col):
    if row == 9:
        print_board(board)
        return True
    if col == 9:
        return solve(board, row + 1, 0)
    if board[row][col] != 0:    #blocked cell
        return solve(board, row, col + 1)
    if board[row][col] == 0:    #free cell
        for k in range(1, 10):
            if no_dup(board, k, row, col) == True:
                board[row][col] = k
                res = solve(board, row, col + 1)
                if res == False:
                    board[row][col] = 0
                else:
                    return True
        return False

#taken from wikipedia
board = [[5,3,0,0,7,0,0,0,0],
         [6,0,0,1,9,5,0,0,0],
         [0,9,8,0,0,0,0,6,0],
         [8,0,0,0,6,0,0,0,3],
         [4,0,0,8,0,3,0,0,1],
         [7,0,0,0,2,0,0,0,6],
         [0,6,0,0,0,0,2,8,0],
         [0,0,0,4,1,9,0,0,5],
         [0,0,0,0,8,0,0,7,9]]

solve(board, 0, 0)
