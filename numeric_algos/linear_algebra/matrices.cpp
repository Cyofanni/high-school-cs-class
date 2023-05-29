#include <iostream>
#include "matrices.h"
using namespace std;

void print_matrix_nrows_5(double mat[][5], const int& n_rows) {
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < 5; j++) {
      cout << mat[i][j] << ' ';
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
