#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(16);
  for (int item : v) {
    cout << item << ' ';
  }

  cout << endl;

  //out_of_range
  //cout << v.at(16) << endl;

  vector<double> nums1 = {5, 6, 5, 8, 7, 13, 15, 98, 78, 25, 14, 1};
  vector<double> nums2 = nums1; //copy, item by item
  nums2.at(0) = 90892;
  for (double item : nums1) {
    cout << item << ' ';
  }
  cout << endl;
  for (double item : nums2) {
    cout << item << ' ';
  }
  cout << endl;

  vector<int> grades;
  int n = 0;
  while (n != -1) {
    cin >> n;
    if (n != -1)
      grades.push_back(n);
  }
  for (auto grade : grades) {
    cout << grade << ' ';
  }
  cout << endl;

  try {
    vector<int> v1(9998988776713877211);
  }
  catch (length_error) {
    cout << "vector max size exceeded" << endl;
  }
}
