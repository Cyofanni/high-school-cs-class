#include <iostream>
#include <iomanip>
using namespace std;

#define N_ROWS 4
#define N_COLS 5

void gaussian_elimination(double A_b[N_ROWS][N_COLS]) {
  for (int r = 0; r < N_ROWS - 1; r++) {
    double pivot = A_b[r][r];
    for (int i = r + 1; i < N_ROWS; i++) {
      double l = A_b[i][r] / pivot;
      for (int j = 0; j < N_COLS; j++) {
	A_b[i][j] = A_b[i][j] - l * A_b[r][j];
      }
    }
  }
}

int main() {
  double aug_system[N_ROWS][N_COLS] = {{3, 1, -1, 8, 25},
				       {-9, -1, 8, -17, 12},
				       {-7, 122, 21, 61, 12},
				       {67, 2, 12, 53, 120}
                                      };
  gaussian_elimination(aug_system);
  for (int i = 0; i < N_ROWS; i++) {
    for (int j = 0; j < N_COLS; j++) {
      cout << setprecision(15) << aug_system[i][j] << ' ';
    }
    cout << endl;
  }
}
