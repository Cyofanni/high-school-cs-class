#include <iostream>
#include <cstdlib>
#include <random>
#include <functional>
#include <cmath>

using namespace std;

double inner_product(double vec1[], double vec2[], size_t size) {
  double result = 0;
  for (size_t i = 0; i <= size - 1; i++) {
    result += vec1[i] * vec2[i];
  }

  return result;
}

void sum_matrices(double *mat1, size_t dim1_1, size_t dim2_1, double *mat2, size_t dim1_2,
                  size_t dim2_2, double *result) {
  if (dim1_1 == dim1_2 && dim2_1 == dim2_2) {
    for (size_t i = 0; i < dim1_1; i++) {
      for (size_t j = 0; j < dim2_1; j++) {
	result[i + j*dim2_1] = mat1[i + j*dim2_1] + mat2[i + j*dim2_2];
      }
    }
  }
  else {
    cerr << "incompatible matrices" << endl;
  }
}

void subtract_rows(double *row1, double *row2, size_t size, double scalar) {
  for (size_t i = 0; i < size; i++) {
    row1[i] = row1[i] - scalar*row2[i];
  }
}

void gaussian_elimination(double *A, double *b, size_t dim, int *err_pivot) {
  for (size_t col = 0; col < dim; col++) {  //loop over columns
    const double pivot = A[col*dim + col]; //the pivot is on the diagonal
    if (pivot == 0) {
      *err_pivot = 1;
      break;
    }
    //start to iterate from below the diagonal
    for (size_t row = col + 1; row < dim; row++) {
      double mult = A[row*dim + col] / pivot;
      cout << mult << endl;
      subtract_rows(A + row*dim, A + col*dim, dim, mult);
      b[row] = b[row] - mult*b[col];
    }
  }
}

void print_matrix(double *mat, size_t dim1, size_t dim2) {
  for (size_t i = 0; i < dim1; i++) {
    for (size_t j = 0; j < dim2; j++) {
      /*
         row_index * row_size = start of row at row_index
         j: offset inside row at row_index
      */
      cout << mat[i*dim2 + j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  double A[3][3] = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
  double b[3] = {8, -11, -3};

  print_matrix(*A, 3, 3);
  cout << endl;
  print_matrix(b, 1, 3);
  cout << endl << endl << endl;
  gaussian_elimination(*A, b, 3);
  cout << endl;
  print_matrix(*A, 3, 3);
  cout << endl;
  print_matrix(b, 1, 3);

  /*
  double mat1[6][6] = {};
  double mat2[6][6] = {};
  double result_sum[6][6] = {};
  auto gen = bind(normal_distribution<double>{30, 2.0}, default_random_engine{});
  auto gen1 = bind(normal_distribution<double>{40, 4.0}, default_random_engine{});

  for (size_t i = 0; i < 6; i++) {
    for (size_t j = 0; j < 6; j++) {
      mat1[i][j] = gen();
    }
  }
  */
}
