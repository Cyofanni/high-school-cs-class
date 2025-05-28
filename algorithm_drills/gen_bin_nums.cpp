#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> numbers;

void gen_bin_numbers(int n, vector<int> number) {
  if (n == 0) {
    numbers.push_back(number);
    return;
  }
  vector<int> number_0 = number;
  number_0.push_back(0);
  gen_bin_numbers(n - 1, number_0);
  vector<int> number_1 = number;
  number_1.push_back(1);
  gen_bin_numbers(n - 1, number_1);
}

int main(int argc, char* argv[]) {
  gen_bin_numbers(3, {});
  for (auto num : numbers) {
    for (auto i : num) {
      cout << i;
    }
    cout << endl;
  }
}
