#include <iostream>
#include <climits>
using namespace std;

//Ex 0 ###
/*this function returns the address
  of a local variable, which is erased
  after return.
*/
int* dangling_ptr_func() {
  int a;
  return &a;
}

//Ex 1 ###
void insertion_sort(int a[], unsigned int size) {
  for (int i = 0; i < size; i++) {
    int item = a[i];
    int j = i - 1;
    while (j >= 0 && item < a[j]){
      a[j + 1] = a[j];
      j -= 1;
    }
    a[j + 1] = item;
  }
}

//sort each row using insertion sort
void sort_rows_1(int m[][16], int num_rows) {
  for (int i = 0; i < num_rows; i++) {
    insertion_sort(m[i], 16);
  }
}

//Ex 2 ###
void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

void selection_sort(int a[], int size) {
  for (int i = 0; i < size; i++) {
    int min_item = a[i];
    int pos_min_item = i;
    for (int j = i + 1; j < size; j++) {
      if (a[j] < min_item) {
	min_item = a[j];
	pos_min_item = j;
      }
    }
    swap(a[i], a[pos_min_item]);
  }
}

//sort each row using selection sort
void sort_rows_2(int m[][16], int num_rows) {
  for (int i = 0; i < num_rows; i++) {
    selection_sort(m[i], 16);
  }
}

//Ex 3 ###
double product(double* matrix, int n_rows, int n_cols) {
  double p = 1;
  bool found_zero = false; //exit loops after first zero
  int i = 0;
  while (i < n_rows && !found_zero) {
    int j = 0;
    while (j < n_cols && !found_zero) {
      p *= matrix[i * n_cols + j];
      if (!matrix[i * n_cols + j]) {
	found_zero = true;
      }
      j = j + 1;
    }
    i = i + 1;
  }
  return p;
}

//Ex 4 ###
void print_dups(char* str, unsigned int len) {
  for (int i = 0; i < len; i++) {
    bool found_dup = false;
    for (int j = i + 1; j < len && !found_dup; j++) {
      if (*(str + i) == *(str + j)) {
	found_dup = true;
      }
    }
    if (found_dup) {
      cout << str[i] << " has duplicate" << endl;
    }
  }
  cout << endl;
}

//Ex 5 ###
unsigned int count_occurs(char* str, int sz, char key) {
  if (!sz) {
    return 0;
  }
  if (*str == key) {
  }
}

int main() {
  /*int matr[][16] = {
    {0, 3, 2, 7, 9, 3, 4, 4, 4, 3, -1, -2, 56, 2, 87, 87},
    {34, -1, -1, 0, 0, 3, 4, 3, 71, 3, -1, 3, 55, 234, 871, 81}
  };

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      cout << matr[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  */

  char st[] = "aaaabba";
  print_dups(st, 7);
}

