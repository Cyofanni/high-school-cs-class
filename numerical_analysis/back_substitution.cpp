#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  const int size = 3;
  double U[size][size] = {{5,6,3},
		    {0,0.8,-0.6},
		    {0,0,2.5}};
  double y[size][1] = {{8},
		       {1.4},
		       {1.5}};
  double x[size][1] = {{0},
		       {0},
		       {0}};

  for (int i = size - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < size; j++) {
      sum = sum + U[i][j] * x[j][0];
    }
    x[i][0] = (y[i][0] - sum) / U[i][i];
  }

  cout << x[0][0] << endl;
  cout << x[1][0] << endl;
  cout << x[2][0] << endl;
}
