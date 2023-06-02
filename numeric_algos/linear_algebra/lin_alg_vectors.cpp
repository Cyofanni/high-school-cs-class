#include <iostream>
#include <vector>
using namespace std;

class bad_mat_mult {
};

class zero_pivot_err {
};

vector<vector<double>> mat_mult(const vector<vector<double>>& a,
                                const vector<vector<double>>& b) {
  int a_n_rows = a.size();
  int a_n_cols = a.at(0).size();
  int b_n_rows = b.size();
  int b_n_cols = b.at(0).size();

  if (a_n_cols != b_n_rows) {
    throw bad_mat_mult();
  }

  vector<vector<double>> res(a_n_rows);
  for (int i = 0; i < a_n_rows; i++) {
    res.at(i).resize(b_n_cols);
    for (int j = 0; j < b_n_cols; j++) {
      for (int k = 0; k < b_n_rows; k++) {
        res.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
      }
    }
  }

  return res;
}

//do not consider 0 pivot
void gauss_elim(vector<vector<double>>& system) {
  int pivot_row = 0, pivot_col = 0;
  int n_rows = system.size();
  int n_cols = system.at(0).size();
  double pivot = system.at(pivot_row).at(pivot_col);
  for (int i = 0; i < n_cols - 1; i++) {
    double pivot = system.at(pivot_row).at(pivot_col);
    if (abs(pivot) <= 1.5e-16) {
      throw zero_pivot_err();
    }
    for (int row = pivot_row + 1; row < n_rows; row++) {
      double l = system.at(row).at(pivot_col) / pivot;
      for (int col = pivot_col; col < n_cols; col++) {
        system.at(row).at(col) -= l * system.at(pivot_row).at(col);
      }
    }
    pivot_row++;
    pivot_col++;
  }
}

void print_matrix(const vector<vector<double>>& mat) {
  for (auto& row : mat) {
    for (auto& el : row) {
      cout << el << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<vector<double>> m1;
  m1.push_back({4.5, 3.2, 7, 9, 1, 2.2});
  m1.push_back({4.8, 3.2, 7, 61, 6, 2.2});
  m1.push_back({4.5, 3.2, 9, 16, 3, 2.1});
  m1.push_back({3.5, 3.2, 0.2, 61, 3, 2.0});

  vector<vector<double>> m2;
  m2.push_back({4.5, 6.2, 7, 9, 1});
  m2.push_back({0.8, 2.2, 7, 61, 6});
  m2.push_back({1.5, 3.2, 9, 16, 3});
  m2.push_back({1.5, 4.2, 0.2, 6, 6});
  m2.push_back({3.5, 13.2, 0.2, 51, 3});
  m2.push_back({3.3, 3.2, 0.2, 2.1, 2});

  vector<vector<double>> m1_m2_prod = mat_mult(m1, m2);
  print_matrix(m1_m2_prod);

  vector<vector<double>> sys = {{6, 4, -1, 12},
				{-3, -1, 2, -11},
				{-2, 1, 2, 8}
                               };
  gauss_elim(sys);
  print_matrix(sys);
}
