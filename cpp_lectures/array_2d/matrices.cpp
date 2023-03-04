#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_matrix(int matr[][4], int rows) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << matr[i][j] << '\t';
    }
    cout << '\n';
  }
}

void print_matrix_recursive(int matr[][4], int rows) {
    if (!rows) {
        return;
    }
    for (int j = 0; j < 4; j++) {
        cout << *(*matr + j) << '\t';
        //cout << (*matr)[j] << '\t';
    }
    cout << endl;
    print_matrix_recursive(matr + 1, rows - 1);
}

int main() {
  int matr[][4] = {{}, {}, {}, {}, {}};
  srand(time(NULL));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      matr[i][j] = rand() % 1000;
    }
  }

  int array_3d[][3][3] = {{{3, 2, 1}, {4, 3, 6}, {6, 5, 7}}, {{4, 3, 6}, {56, 45, 34}, {12, 13, 14}},
                         {{34, 67, 56}, {12, 13, 14}, {23, 14, 1}},
                         {{34, 47, 2}, {23, 14, 15}, {56, 45, 34}}, {{23, 14, 6}, {56, 45, 34}, {23, 14, 5}}};

  print_matrix(matr, 5);
  cout << endl;
  print_matrix_recursive(matr, 5);
}
