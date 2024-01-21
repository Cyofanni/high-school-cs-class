import math, random

board_size = 9
bs_sqrt = int(math.sqrt(board_size))

def print_board(board):
    for i in range(board_size):
        for j in range(board_size):
            print(board[i][j], end = '')
            print(' ', end = '')
            if j % bs_sqrt == bs_sqrt - 1:
                print(' ', end = '')
        print()
        if i % bs_sqrt == bs_sqrt - 1:
            print('\n')

def get_block_start(row, col):
    grid_num = (row // bs_sqrt) * bs_sqrt + col // bs_sqrt
    return (grid_num - (grid_num % bs_sqrt), (grid_num % bs_sqrt) * bs_sqrt)

#brute-force algorithm
def no_dup(board, num, row, col):
    #check row
    for j in range(board_size):
        if j != col and board[row][j] == num:
            return False
    #check column
    for j in range(board_size):
        if j != row and board[j][col] == num:
            return False
    #check block
    block_start_row = get_block_start(row, col)[0]
    block_start_col = get_block_start(row, col)[1]
    for i in range(block_start_row, block_start_row + bs_sqrt):
        for j in range(block_start_col, block_start_col + bs_sqrt):
            if i != row and j != col and board[i][j] == num:
                return False

    return True

def next_pos(row, col):
    if col == board_size - 1:
        return (row + 1, 0)
    return (row, col + 1)

#brute-force algorithm
def is_sol_valid(board):
    for i in range(board_size):
        for j in range(board_size):
            if no_dup(board, board[i][j], i, j) == False:
                return False
    return True

def solve_and_print_sols(board, row, col):
    if row == board_size:
        if is_sol_valid(board) == True:
            print("valid:\n")
            print_board(board)
            print()
            print()
            return True
        return False

    if board[row][col] == 0:
        for num in range(1, board_size + 1):
            if no_dup(board, num, row, col):
                board[row][col] = num
                solve_and_print_sols(board, next_pos(row, col)[0], next_pos(row, col)[1])
                board[row][col] = 0
        return False

    return solve_and_print_sols(board, next_pos(row, col)[0], next_pos(row, col)[1])

#board = [[random.randint(0, board_size) for _ in range(board_size)] for _ in range(board_size)]
board = [[5,3,0,0,7,0,0,0,0],
         [6,0,0,1,9,5,0,0,0],
         [0,9,8,0,0,0,0,6,0],
         [8,0,0,0,6,0,0,0,3],
         [4,0,0,8,0,3,0,0,1],
         [7,0,0,0,2,0,0,0,6],
         [0,6,0,0,0,0,2,8,0],
         [0,0,0,4,1,9,0,0,5],
         [0,0,0,0,8,0,0,7,9]]

solve_and_print_sols(board, 0, 0)

