#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerset = {};

void gen_subsets(vector<int>& nums, int k, vector<int> subset) {
  if (k == nums.size()) {
    powerset.push_back(subset);
    return;
  }
  vector<int> subset_copy = subset;
  subset_copy.push_back(nums.at(k));
  gen_subsets(nums, k + 1, subset_copy);
  gen_subsets(nums, k + 1, subset);
}

int main() {
  vector<int> nums = {0, 1, 2, 3};
  vector<int> subs = {};
  gen_subsets(nums, 0, subs);
  cout << "powerset size: " << powerset.size() << endl;
  for (vector<int> subset : powerset) {
    if (subset.size() == 0) {
      cout << "EMPTY_SET" << endl;
    }
    else {
      for (int item : subset) {
	cout << item << ' ';
      }
      cout << endl;
    }
  }
}
