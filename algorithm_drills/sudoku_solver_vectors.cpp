#include <iostream>
#include <vector>
using namespace std;

typedef struct pos {
  int row;
  int col;
} pos;

void print_board(const vector<vector<int>>& board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board.at(i).at(j) << ' ';
      if (j % 3 == 2) {
        cout << "  ";
      }
      else {
	cout << " ";
      }
    }
    if (i % 3 == 2) {
      cout << endl << endl;
    }
    else {
      cout << endl;
    }
  }
}

pos get_block_start(const pos& p) {
  int row = p.row, col = p.col;
  int grid_num = (row / 3) * 3 + col / 3;
  if (grid_num == 0) {
    return {0, 0};
  }
  else if (grid_num == 1) {
    return {0, 3};
  }
  else if (grid_num == 2) {
    return {0, 6};
  }
  else if (grid_num == 3) {
    return {3, 0};
  }
  else if (grid_num == 4) {
    return {3, 3};
  }
  else if (grid_num == 5) {
    return {3, 6};
  }
  else if (grid_num == 6) {
    return {6, 0};
  }
  else if (grid_num == 7) {
    return {6, 3};
  }
  else if (grid_num == 8) {
    return {6, 6};
  }
  else {
    return {-1, -1};
  }
}

bool no_dup(const vector<vector<int>>& board, int num, const pos& p) {
  //check row
  int row = p.row, col = p.col;
  for (int i = 0; i < 9; i++) {
    if (i != col && board[row][i] == num) {
      return false;
    }
  }
  //check column
  for (int i = 0; i < 9; i++) {
    if (i != row && board[i][col] == num) {
      return false;
    }
  }
  //check block
  int block_start_row = get_block_start(p).row;
  int block_start_col = get_block_start(p).col;
  for (int i = block_start_row; i < block_start_row + 3; i++) {
    for (int j = block_start_col; j < block_start_col + 3; j++) {
      if (i != row && j != col && board.at(i).at(j) == num) {
	return false;
      }
    }
  }

  return true;
}

pos next_pos(const pos& p) {
  if (p.col == 8) {
    return {p.row + 1, 0};
  }
  return {p.row, p.col + 1};
}

bool is_sol_valid(const vector<vector<int>>& board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (!no_dup(board, board.at(i).at(j), {i, j})) {
	return false;
      }
    }
  }

  return true;
}

bool solve_and_print(vector<vector<int>>& board, const pos& p) {
  if (p.row == 9) {
    print_board(board);
    if (is_sol_valid(board)) {
      cout << endl << "valid" << endl << endl;
    }
    return true;
  }
  //free cell
  if (board.at(p.row).at(p.col) == 0) {
    for (int num = 1; num <= 9; num++) {
      if (no_dup(board, num, p)) {
	board.at(p.row).at(p.col) = num;
	solve_and_print(board, next_pos(p));
	board.at(p.row).at(p.col) = 0;
      }
    }
    return false;
  }
  return solve_and_print(board, next_pos(p));
}

int main(int argc, char* argv[]) {
  vector<vector<int>> board = {{5,3,0,0,7,0,0,0,0},
			       {6,0,0,1,9,5,0,0,0},
			       {0,9,8,0,0,0,0,6,0},
			       {8,0,0,0,6,0,0,0,3},
			       {4,0,0,8,0,3,0,0,1},
			       {7,0,0,0,2,0,0,0,6},
			       {0,6,0,0,0,0,2,8,0},
			       {0,0,0,4,1,9,0,0,5},
			       {0,0,0,0,8,0,0,0,0}};
  solve_and_print(board, {0, 0});
}
