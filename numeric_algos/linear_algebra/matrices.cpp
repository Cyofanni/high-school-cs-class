#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void print_array_2d_by_rows(double* matrix, unsigned int num_rows,
			    unsigned int num_cols) {
  for (int ind_row = 0; ind_row < num_rows; ind_row++) {
    for (int ind_col = 0; ind_col < num_cols; ind_col++) {
      //num_cols: length of a row
      cout << matrix[ind_row * num_cols + ind_col] << "    ";
    }
    cout << endl;
  }
  cout << endl;
}

void print_array_2d_by_columns(double* matrix, unsigned int num_rows,
			       unsigned int num_cols) {
  for (int ind_col = 0; ind_col < num_cols; ind_col++) {
    for (int ind_row = 0; ind_row < num_rows; ind_row++) {
      //num_cols: length of a row
      cout << matrix[ind_row * num_cols + ind_col] << endl;
    }
    cout << endl;
  }
  cout << endl;
}

void print_array_3d_by_surfaces(double* cube, unsigned int depth,
				unsigned int length, unsigned int height) {
  for (int ind_surface = 0; ind_surface < depth; ind_surface++) {
    for (int ind_row = 0; ind_row < length; ind_row++) {
      for (int ind_col = 0; ind_col < height; ind_col++) {
	//length * height: size of a surface, height: size of a row
	cout << cube[ind_surface * length * height + ind_row * height + ind_col]
	     << "  ";
      }
      cout << endl;
    }
    cout << endl << endl;
  }
  cout << endl;
}

void transpose_5_4(double matrix[5][4], double matrix_t[4][5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      matrix_t[i][j] = matrix[j][i];
    }
  }
}

int main() {
  cout << setprecision(8);
  double matrix[4][4];
  srand(time(NULL));
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      matrix[i][j] = (double)(rand() % 1000) / (i + j + 1);
      //cout << matrix[i][j] << "    ";
    }
    //cout << endl;
  }
}
