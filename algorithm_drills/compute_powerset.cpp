#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerset = {};

void gen_subsets(vector<int>& nums, int k, vector<int>& subset) {
  if (k == nums.size()) {
    powerset.push_back(subset);
    return;
  }
  subset.push_back(nums[k]);
  gen_subsets(nums, k + 1, subset);
  subset.pop_back();
  gen_subsets(nums, k + 1, subset);
}

int main() {
  vector<int> nums = {3, 1};
  vector<int> subs = {};
  gen_subsets(nums, 0, subs);
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
