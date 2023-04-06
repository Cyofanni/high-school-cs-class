#include <iostream>
#include <climits>

using namespace std;

int main() {
  int arr1[11] = {2, 4, 6, 6, 10, 11, 12, 12, 18, 20, INT_MAX};
  int arr2[11] = {1, 4, 5, 7, 9, 11, 13, 15, 17, 19, INT_MAX};
  int merged_array[20];
  int arr1_index = 0, arr2_index = 0;

  for (int i = 0; i < 20; i++) {
    if (arr1[arr1_index] <= arr2[arr2_index]) {
      merged_array[i] = arr1[arr1_index];
      arr1_index++;
    }
    else {
      merged_array[i] = arr2[arr2_index];
      arr2_index++;
    }
  }

  for (int i = 0; i < 20; i++) {
    cout << merged_array[i] << ' ';
  }
  cout << endl;
}
