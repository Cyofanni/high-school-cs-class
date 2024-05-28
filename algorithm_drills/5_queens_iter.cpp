#include <iostream>
using namespace std;

#define B_SIZE 5

void print_chessboard(char board[B_SIZE][B_SIZE]) {
  for (int i = 0; i < B_SIZE; i++) {
    for (int j = 0; j < B_SIZE; j++) {
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void place_queen(char board[B_SIZE][B_SIZE], int i, int j) {
  board[i][j] = 'Q';
}

void erase_queen(char board[B_SIZE][B_SIZE], int i, int j) {
  board[i][j] = '-';
}

bool is_safe(char board[][B_SIZE], int i, int j) {
  bool safe = true;
  int col_back = j, col_diag_left = j - 1, col_diag_right = j + 1;
  for (int row = i - 1; row >= 0 && safe; row--){
    if (board[row][col_back] == 'Q' ||
	(col_diag_left >= 0 && board[row][col_diag_left] == 'Q') ||
	(col_diag_right < B_SIZE && board[row][col_diag_right] == 'Q')) {
      safe = false;
    }
    col_diag_left--;
    col_diag_right++;
  }

  return safe;
}

int five_queens(char board[B_SIZE][B_SIZE]) {
  int i = 0;
  int solutions = 0;
  for (int j = 0; j < B_SIZE; j++) {
    if (is_safe(board, i, j)) {
      place_queen(board, i, j);
      i++;
      for (int j = 0; j < B_SIZE; j++) {
	if (is_safe(board, i, j)) {
	  place_queen(board, i, j);
	  i++;
	  for (int j = 0; j < B_SIZE; j++) {
	    if (is_safe(board, i, j)) {
	      place_queen(board, i, j);
	      i++;
	      for (int j = 0; j < B_SIZE; j++) {
		if (is_safe(board, i, j)) {
		  place_queen(board, i, j);
		  i++;
		  for (int j = 0; j < B_SIZE; j++) {
		    if (is_safe(board, i, j)) {
		      place_queen(board, i, j);
		      print_chessboard(board);
		      solutions++;
		      erase_queen(board, i, j);
		    }
		  }
		  i--;
		  erase_queen(board, i, j);
		}
	      }
	      i--;
	      erase_queen(board, i, j);
	    }
	  }
	  i--;
	  erase_queen(board, i, j);
	}
      }
      i--;
      erase_queen(board, i, j);
    }
  }

  return solutions;
}

int main(int argc, char* argv[]) {
  char chessboard[B_SIZE][B_SIZE];
  for (int i = 0; i < B_SIZE; i++) {
    for (int j = 0; j < B_SIZE; j++) {
      chessboard[i][j] = '-';
    }
  }

  int q = five_queens(chessboard);
  cout << endl << q << endl;
}
