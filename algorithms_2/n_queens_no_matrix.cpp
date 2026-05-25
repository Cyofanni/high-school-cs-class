#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 10

void print_chessboard(int queens[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    int pos = queens[i];
    int j;
    for (j = 0; j < pos; j++) {
      cout << '_' << ' ';
    }
    if (queens[i] >= 0) {
      cout << 'Q' << ' ';
    }
    else {
      cout << '_' << ' ';
    }
    for (int k = j + 1; k < SIZE; k++) {
      cout << '_' << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

bool is_pos_safe(int queens[SIZE], int r, int c) {
  for (int j = r - 1; j >= 0; j--) {
    int pos = queens[j];
    if (pos == c || abs(r - j) == abs(c - pos)) {
      return false;
    }
  }
  return true;
}

int num_solutions = 0;

void n_queens_solver(int queens[SIZE], int r) {
  if (r == SIZE) {
    print_chessboard(queens);
    num_solutions++;
    return;
  }
  for (int c = 0; c < SIZE; c++) {
    if (is_pos_safe(queens, r, c) == true) {
      queens[r] = c;
      n_queens_solver(queens, r + 1);
      queens[r] = -1;
    }
  }
}

int main() {
  int queens[SIZE] = {-1};
  n_queens_solver(queens, 0);
  cout << num_solutions << endl;
}
