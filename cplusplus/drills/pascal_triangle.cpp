#include <iostream>
using namespace std;

#define NUM_ROWS_PASCAL 8
#define NUM_COLS_PASCAL 15

int main() {
  int pascal_triangle[NUM_ROWS_PASCAL][NUM_COLS_PASCAL] = {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                                           {}, {}, {}, {}, {}, {}, {}};
  int first_index_col = 6, last_index_col = 8;
  /*
      0 0 0 0 1 0 0 0 0
      0 0 0 1 0 1 0 0 0
      0 0 1 0 2 0 1 0 0
      0 1 0 3 0 3 0 1 0
      1 0 4 0 6 0 4 0 1
           etc...
  */
  for (int i = 1; i < NUM_ROWS_PASCAL; i++) {
    for (int j = first_index_col; j <= last_index_col; j += 2) {
      if (j >= 1 && j <= 13) {
        pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j + 1];
      }
      else {
        pascal_triangle[i][j] = 1;
      }
    }
    first_index_col--;
    last_index_col++;
  }

  for (int i = 0; i < NUM_ROWS_PASCAL; i++) {
    for (int j = 0; j < NUM_COLS_PASCAL; j++) {
      if (pascal_triangle[i][j] != 0) {
        cout << pascal_triangle[i][j] << ' ';
      }
      else {
        cout << ' ';
      }
    }
    cout << endl;
  }
  cout << endl;
}
