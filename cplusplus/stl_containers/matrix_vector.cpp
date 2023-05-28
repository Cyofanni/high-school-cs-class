#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<vector<int>> matrix;
  matrix.push_back({5, 7, 8, 1, 1});
  matrix.push_back({8, 1, 3, 9, 5});
  matrix.push_back({3, 7, 8, 1, 4});
  matrix.push_back({3, 7, 8, 4, 1});

  for (auto row : matrix) {
    for (auto elem : row) {
      cout << elem << ' ';
    }
    cout << endl;
  }
}
