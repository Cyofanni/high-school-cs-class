#include <iostream>
#include <climits>

using namespace std;

void merge(int a[], int p, int q, int r) {
  //allocate left and right arrays on the heap
  int sz_left = q - p + 1 + 1;
  int sz_right = r - q + 1;
  int *left = new int[sz_left];
  int *right = new int[sz_right];
  /*
  could have used variable-length arrays
  int left[sz_left];
  int right[sz_right];
  */

  int i, j;
  for (i = 0; i <= sz_left - 2; i++) {
    left[i] = a[p + i];
  }
  left[i] = INT_MAX;

  for (j = 0; j <= sz_right - 2; j++) {
    right[j] = a[q + 1 + j];
  }
  right[j] = INT_MAX;

  int left_index = 0, right_index = 0;
  for (int a_index = p; a_index <= r; a_index++) {
    if (left[left_index] <= right[right_index]) {
      a[a_index] = left[left_index];
      left_index++;
    }
    else {
      a[a_index] = right[right_index];
      right_index++;
    }
  }

  delete[] left;
  delete[] right;
}

void merge_sort(int a[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

void print_array(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << '\t';
  }
  cout << '\n';
}

int main(){
  int arr[] = {10, 2, 4, 2, 34, 1, 23, 123, 67};
  merge_sort(arr, 0, 8);
  print_array(arr, 9);
}
