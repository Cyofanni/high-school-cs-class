#include <iostream>
#include "matrices.h"
using namespace std;

void print_matrix(double mat[], const int& n_rows,
		  const int& n_cols) {
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      cout << mat[i * n_cols + j] << ' ';
    }
    cout << endl;
  }
}

void matrix_mult(double matr1[4][6], double matr2[6][5],
		    double matr3[4][5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 6; k++) {
	matr3[i][j] += matr1[i][k] * matr2[k][j];
      }
    }
  }
}

void gaussian_elimination(double system[3][4]) {
  int pivot_row = 0;

  for (int pivot_col = 0; pivot_col < 4; pivot_col++) {
    for (int row = pivot_row + 1; row < 3; row++) {
      double l = system[row][pivot_col] / system[pivot_row][pivot_col];
      for (int col = 0; col < 4; col++) {
	system[row][col] = system[row][col] - l * system[pivot_row][col];
      }
    }
    pivot_row++;
  }
}
