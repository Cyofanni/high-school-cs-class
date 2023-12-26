#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  vector<vector<double>> A_b = {{2,1,-1,8},
			       {-3,-1,2,-11},
			       {-2,1,2,-3}};
  int n_rows = A_b.size();
  int n_cols = A_b.at(0).size();

  for (int i = 0; i <= n_cols - 2; i++) {
    double u = A_b.at(i).at(i);
    for (int j = i + 1; j <= n_rows - 1; j++) {
      double l = A_b.at(j).at(i) / u;
      for (int k = i; k <= n_cols - 1; k++) {
	A_b.at(j).at(k)= A_b.at(j).at(k) - l * A_b.at(i).at(k);
      }
    }
  }
  for (auto row: A_b) {
    for (auto item: row) {
      cout << item << ' ';
    }
    cout << endl;
  }

  //back substitution
  vector<double> x(n_rows);
  for (int i = n_rows - 1; i >= 0; i--) {
    double b = A_b.at(i).at(n_cols - 1);
    double sum = 0;
    for (int j = i + 1; j <= n_cols - 2; j++) {
      sum += A_b.at(i).at(j) * x.at(j);
    }
    x.at(i) = (b - sum) / A_b.at(i).at(i);
  }
  cout << endl;
  for (auto item: x) {
    cout << item << endl;
  }
}
