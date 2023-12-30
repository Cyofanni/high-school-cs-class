#include <iostream>
using namespace std;

#define CHESSBOARD_SIZE 14

void print_chessboard(char board[][CHESSBOARD_SIZE]) {
  for (int i = 0; i < CHESSBOARD_SIZE; i++) {
    for (int j = 0; j < CHESSBOARD_SIZE; j++) {
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void place_queen(char board[][CHESSBOARD_SIZE], int i, int j) {
  board[i][j] = 'Q';
}

void erase_queen(char board[][CHESSBOARD_SIZE], int i, int j) {
  board[i][j] = '-';
}

bool is_pos_safe(char board[][CHESSBOARD_SIZE], int i, int j) {
  bool safe = true, inside = true;
  int col_back = j, col_diag_left = j - 1, col_diag_right = j + 1;
  for (int row = i - 1; row >= 0 && safe; row--){
    if (board[row][col_back] == 'Q' ||
	(col_diag_left >= 0 && board[row][col_diag_left] == 'Q') ||
	(col_diag_right < CHESSBOARD_SIZE && board[row][col_diag_right] == 'Q')) {
      safe = false;
    }
    col_diag_left--;
    col_diag_right++;
  }

  return safe;
}

int n_queens(char board[][CHESSBOARD_SIZE], int row) {
  if (row == CHESSBOARD_SIZE) {
    print_chessboard(board);
    return 1;
  }
  int n_sols = 0;
  for (int col = 0; col < CHESSBOARD_SIZE; col++) {
    if (is_pos_safe(board, row, col)) {
      place_queen(board, row, col);
      n_sols = n_sols + n_queens(board, row + 1);
      erase_queen(board, row, col);
    }
  }

  return n_sols;
}

int main(int argc, char* argv[]) {
  char chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE];
  for (int i = 0; i < CHESSBOARD_SIZE; i++) {
    for (int j = 0; j < CHESSBOARD_SIZE; j++) {
      chessboard[i][j] = '-';
    }
  }
  int num_sols = n_queens(chessboard, 0);
  cout << num_sols << endl;
}
