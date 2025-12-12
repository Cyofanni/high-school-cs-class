#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  //const int n_rows = 3, n_cols = 4;
  const int n_rows = 4, n_cols = 5;
  /*double A_b[n_rows][n_cols] = {{6,4,-1,12},
			       {-3,-1,2,-11},
			       {-2,1,2,8}};*/
  /*double A_b[n_rows][n_cols] = {{2,1,-1,8},
			       {-3,-1,2,-11},
			       {-2,1,2,-3}};
  */
  /*double A_b[n_rows][n_cols] = {{2,1,-1,6,8},
				{4,-3,-1,2,-11},
				{-2,1,2,8,-3},
				{6,6,2,8.2,-3}};
  */
  double A_b[n_rows][n_cols] = {{2,13,-13,2,3},
				{3,-3,-1,2,11},
				{-2,1,2,1,-3},
				{3,12,2,8.2,-15}};

  //loop over diagonal items
  for (int i = 0; i <= n_rows - 2; i++) {
    double u = A_b[i][i];
    //u could be 0, or very small (don't care for this example)
    //loop over item's column (below the item)
    for (int j = i + 1; j <= n_rows - 1; j++) {
      double l = A_b[j][i] / u;
      //loop on the row
      for (int k = i; k <= n_cols - 1; k++) {
        A_b[j][k] = A_b[j][k] - l * A_b[i][k];
      }
    }
  }
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      cout << A_b[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  //back substitution
  double x[n_rows];
  for (int i = n_rows - 1; i >= 0; i--) {
    double b = A_b[i][n_cols - 1];
    double sum = 0;
    for (int j = i + 1; j <= n_cols - 2; j++) {
      sum = sum + A_b[i][j] * x[j];
    }
    x[i] = (b - sum) / A_b[i][i];
  }
  for (int i = 0; i < n_rows; i++) {
    cout << x[i] << ' ';
  }
  cout << endl;
}
