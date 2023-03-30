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

void print_matrix_by_cols(int matr[][4], int n_rows) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n_rows; ++j) {
      cout << matr[j][i] << '\n';
    }
    cout << endl;
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

void swap_rows(int matr[][4], int n_rows) {
  for (int i = 0; i <= n_rows - 2; i += 2) {
    for (int j = 0; j < 4; j++) {
      int t = matr[i][j];
      matr[i][j] = matr[i + 1][j];
      matr[i + 1][j] = t;
    }
  }
}

void transpose(int matr[3][4], int matr_t[4][3]) {
  for (int i = 0; i < 4; i++) { //loop over matr_t rows
    for (int j = 0; j < 3; j++) {
      matr_t[i][j] = matr[j][i];
    }
  }
}

void swap_cols(int matr[][4], int n_rows) {
  for (int i = 0; i <= 2; i += 2) {
    for (int j = 0; j < n_rows; j++) {
      int t = matr[j][i];
      matr[j][i] = matr[j][i + 1];
      matr[j][i + 1] = t;
    }
  }
}

void matrix_multiplication(int matr1[4][3], int matr2[3][2], int matr_result[4][2]) {
  for (int i = 0; i < 4; i++) { //loop over matr_result
    for (int j = 0; j < 2; j++) {
      int inner_product_i_j = 0;
      //compute matr1:i-th row * matr2:j-th col
      for (int k = 0; k < 3; k++) {
	inner_product_i_j = inner_product_i_j + matr1[i][k] * matr2[k][j];
      }
      matr_result[i][j] = inner_product_i_j;
    }
  }
}

int main() {
  int matr[][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {1, 3, 4, 6},
			       {12, 13, 14, 16}, {24, 26, 27, 28}, {41, 48, 37, 5}};
  cout << "#initial matrix, by rows: " << endl;
  print_matrix(matr, 6);
  cout << endl;
  cout << "#rows swapped: " << endl;
  swap_rows(matr, 6);
  print_matrix(matr, 6);
  cout << endl;
  cout << "#by columns: " << endl;
  print_matrix_by_cols(matr, 6);
  cout << endl;
  swap_cols(matr, 6);
  cout << "#columns swapped: " << endl;
  print_matrix(matr, 6);

  cout << endl;
  cout << "#transpose: " << endl;
  int mat1[3][4] = {{4, 5, 6, 7}, {1, 3, 5, 7}, {1, 8, 7, 6}};
  cout << "initial matrix: " << endl;
  print_matrix(mat1, 3);
  int mat1_t[4][3];
  transpose(mat1, mat1_t);
  cout << endl << "transposed: " << endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << mat1_t[i][j] << '\t';
    }
    cout << '\n';
  }

  cout << endl;
  cout << "#matrix multiplication: " << endl;
  int A[4][3] = {{1, 2, 3}, {5, 4, 23}, {8, 5, 9}, {6, 1, 5}};
  int B[3][2] = {{5, 3}, {7, 9}, {67, 12}};

  cout << "A: " << endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << A[i][j] << '\t';
    }
    cout << '\n';
  }
  cout << endl << endl;
  cout << "B: " << endl;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << B[i][j] << '\t';
    }
    cout << '\n';
  }
  cout << endl;

  int C[4][2];
  matrix_multiplication(A, B, C);
  cout << "C: " << endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << C[i][j] << '\t';
    }
    cout << '\n';
  }
  cout << endl;
}
