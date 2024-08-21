import random

#recursive calls only on free and white slots
def solve(mz, row, col, n_rows, n_cols):
    if row == n_rows - 1:
        return True

    if mz[row][col - 1][0] == 'X' and mz[row + 1][col][0] == 'X' \
       and mz[row][col + 1][0] == 'X':
            return False

    mz[row][col][1] = 'G'
    left, down, right = False, False, False
    #left
    if mz[row][col - 1][1] == 'W' and mz[row][col - 1][0] == '_':
        left = solve(mz, row, col - 1, n_rows, n_cols)

    #down
    if mz[row + 1][col][1] == 'W' and mz[row + 1][col][0] == '_':
        down = solve(mz, row + 1, col, n_rows, n_cols)

    #right
    if mz[row][col + 1][1] == 'W' and mz[row][col + 1][0] == '_':
        right = solve(mz, row, col + 1, n_rows, n_cols)

    mz[row][col][1] = 'B'
    return left or down or right

def generate_maze(n_rows, n_cols):
    mz = [[None for _ in range(n_cols)] for _ in range(n_rows)]
    for i in range(n_rows):
        for j in range(n_cols):
            r = random.randint(0, 3)
            if j == 0 or j == n_cols - 1:
                mz[i][j] = ['X', 'W']
            else:
                if r == 0 or r == 1:
                    mz[i][j] = ['X', 'W']
                else:
                    mz[i][j] = ['_', 'W']
    return mz

def print_maze(mz):
    print('\n\n')
    print(' ' * 15, 'entrance side\n')
    for row in mz:
        print(' ' * 16, end = '')
        for item in row[1:len(row)-1]:
            print(item[0], end = '   ')
        print('\n')
    print(' ' * 15, 'exit side')
    print()

maze = generate_maze(8, 10)
#entrance as column index
entrance = 6
maze[0][entrance][0] = '_'
for i in range(len(maze[0])):
    if i != entrance:
        maze[0][i][0] = 'X'

print_maze(maze)
res = solve(maze, 0, entrance, len(maze), len(maze[0]) - 1)
if res:
    print('PATH FOUND')
else:
    print('PATH NOT FOUND')
