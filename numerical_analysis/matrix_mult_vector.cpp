#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  vector<vector<double>> m1;
  m1.push_back({6,5,4,4});
  m1.push_back({8,2,1,3});
  m1.push_back({6,5,3,1});
  int m1_n_rows = m1.size();
  int m1_n_cols = m1.at(0).size();

  vector<vector<double>> m2;
  m2.push_back({7,4,1,4,3});
  m2.push_back({6,8,2,6,3});
  m2.push_back({5,8,6,3,4});
  m2.push_back({9,7,7,2,5});
  int m2_n_rows = m2.size();
  int m2_n_cols = m2.at(0).size();

  vector<vector<double>> m3;
  for (int i = 0; i < m1_n_rows; i++) {
    m3.push_back({});
  }
  for (int i = 0; i < m1_n_rows; i++) {
    for (int j = 0; j < m2_n_cols; j++) {
      double sum = 0;
      for (int k = 0; k < m1_n_cols; k++) {
	sum = sum + m1.at(i).at(k) * m2.at(k).at(j);
      }
      m3.at(i).push_back(sum);
    }
  }
  for (int i = 0; i < m1_n_rows; i++) {
    for (int j = 0; j < m2_n_cols; j++) {
      cout << m3.at(i).at(j) << ' ';
    }
    cout << endl;
  }
}
