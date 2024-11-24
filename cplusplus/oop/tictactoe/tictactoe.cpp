#include "tictactoe.h"
using namespace std;

void tictactoe::switch_player_mark() {
  if (curr_player_mark == 'X') {
    curr_player_mark = 'O';
  }
  else {
    curr_player_mark = 'X';
  }
}

bool tictactoe::check_win() const {
  int count_marks = 0;

  for (int r = 0; r < 3; r++) {
    count_marks = 0;
    for (int j = 0; j < 3 && board[r][j] == curr_player_mark; j++) {
      count_marks++;
    }
    if (count_marks == 3) {
      return true;
    }
  }

  for (int c = 0; c < 3; c++) {
    count_marks = 0;
    for (int r = 0; r < 3 && board[r][c] == curr_player_mark; r++) {
      count_marks++;
    }
    if (count_marks == 3) {
      return true;
    }
  }

  count_marks = 0;
  for (int i = 0; i < 3 && board[i][i] == curr_player_mark; i++) {
    count_marks++;
  }
  if (count_marks == 3) {
    return true;
  }

  count_marks = 0;
  for (int i = 0; i < 3 && board[i][2 - i] == curr_player_mark; i++) {
    count_marks++;
  }
  if (count_marks == 3) {
    return true;
  }

  return false;
}

tictactoe::tictactoe(char init_player_mark) {
  curr_player_mark = init_player_mark;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '_';
    }
  }
}

char tictactoe::get_player_mark() const {
  return curr_player_mark;
}

bool tictactoe::make_move_check_win(int i, int j) {
  board[i][j] = curr_player_mark;
  bool won = check_win();

  //if current player won, do not switch player
  if (!won) {
    switch_player_mark();
  }
  return won;
}

void tictactoe::draw() const {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << "  ";
    }
    cout << endl;
  }
}
