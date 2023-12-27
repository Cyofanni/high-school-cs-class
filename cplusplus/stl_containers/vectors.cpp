#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //example 0
  vector<int> v(16);
  for (int item : v) {
    cout << item << ' ';
  }
  cout << endl;
  //out_of_range
  //cout << v.at(16) << endl;

  //example 1
  cout << endl;
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

  //example 2
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

  //example 3
  cout << endl;
  try {
    vector<int> v1(9998988776713877211);
  }
  catch (length_error) {
    cout << "vector max size exceeded" << endl;
  }

  //example 4 (iterator)
  cout << endl;
  vector<int> vec1 = {6, 8, 7, 1, 6, 7};
  vector<int>::iterator it;
  it = find(vec1.begin(), vec1.end(), 7);
  if (it != vec1.end()) {
    cout << *it << endl;
  }

  //example 5 (matrix)
  vector<vector<double>> matrix = {{4, 5, 3},
                                   {1, 2, 3},
                                   {6, 5, 4}};
  cout << endl;
  for (auto row : matrix) {
    for (auto item : row) {
       cout << item << ' ';
    }
    cout << endl;
  }

  //example 6 (size vs capacity)
  cout << endl;
  vector<int> v6(2);
  for (int i = 1; i <= 1000; i++) {
    cout << "size: " << v6.size() << ", capacity: " << v6.capacity() << endl;
    v6.push_back(i);
  }
}
