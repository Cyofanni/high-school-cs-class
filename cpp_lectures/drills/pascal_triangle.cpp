#include <iostream>
#include <cstdio>
using namespace std;

#define NUM_ROWS_PASCAL 8
#define NUM_COLS_PASCAL 15

int main() {
  int pascal_triangle[NUM_ROWS_PASCAL][NUM_COLS_PASCAL] = {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}, {}, {}, {}, {}};
  int first_index_row = 6;
  /*
      0 0 0 0 1 0 0 0 0
      0 0 0 1 0 1 0 0 0
      0 0 1 0 2 0 1 0 0
      0 1 0 3 0 3 0 1 0
      1 0 4 0 6 0 4 0 1
           etc...
  */
  for (int i = 1; i < NUM_ROWS_PASCAL; i++) {
    for (int j = first_index_row; j < NUM_COLS_PASCAL; j += 2) {
      if (j > 0 && j < 14) {
	pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j + 1];
      }
      else if (j == 0) {
	pascal_triangle[i][j] = pascal_triangle[i - 1][j + 1];
      }
      else {
	pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1];
      }
    }
    first_index_row--;
  }
  for (int i = 0; i < NUM_ROWS_PASCAL; i++) {
    for (int j = 0; j < NUM_COLS_PASCAL; j++){
      if (pascal_triangle[i][j] != 0) {
	cout << pascal_triangle[i][j] << "    ";
      }
      else {
	cout << "   ";
      }
    }
    cout << endl;
  }
  cout << endl;
}
