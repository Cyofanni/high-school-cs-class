#include <iostream>
#include <climits>
#include <cstring>
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
    //count occurrences in the remainder of the string
    unsigned int count_tail = count_occurs(str + 1, sz - 1, key);
    //add 1 and return
    return count_tail + 1;
  }
  //otherwise, continue scanning the remainder of the string
  return count_occurs(str + 1, sz - 1, key);
}

//Ex 6 ###
bool binary_search_i(int* a, int size, int key) {
  int low = 0, high = size - 1;
  bool found = false;
  while (!found && low <= high) {
    int middle = (low + high) / 2;
    if (key == *(a + middle)) {
      found = true;
    }
    else if (key < *(a + middle)) {
      high = middle - 1;
    }
    else {
      low = middle + 1;
    }
  }

  return found;
}

bool binary_search_r(int* a, int low, int high, int key) {
  if (low > high) {
    return false;
  }
  int middle = (low + high) / 2;
  if (key == a[middle]) {
    return true;
  }
  if (key < a[middle]) {
    return binary_search_r(a, low, middle - 1, key);
  }
  return binary_search_r(a, middle + 1, high, key);
}

/*search for key in each row, return index of row with first
  occurrence of key*/
int search_key_matrix(int matrix[][5], int num_rows, int key) {
  int row_index = -1;
  bool found_row = false;
  for (int i = 0; i < num_rows && !found_row; i++) {
    if (!(i % 2)) {
      found_row = binary_search_i(matrix[i], 5, key);
    }
    else {
      found_row = binary_search_r(matrix[i], 0, 4, key);
    }
    if (found_row) {
      row_index = i;
    } 
  }

  return row_index;
}

//Ex 7 ###
void print_array_rec_rec(int* a, int low, int high) {
  if (low <= high) {
    int middle = (low + high) / 2;
    print_array_rec_rec(a, low, middle - 1);
    cout << a[middle] << ' ';
    print_array_rec_rec(a, middle + 1, high);
  }
}

//Ex 8 ###
int count_occurr_iter(int* arr, int size, int key) {
  int counter = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == key) {
      counter++;
    }
  }
  return counter;
}

int count_occur_tail_rec(int* arr, int size, int key, int counter) {
  if (!size) {
    return counter;
  }
  if (*arr == key) {
    return count_occur_tail_rec(arr + 1, size - 1, key, counter + 1);
  }
  return count_occur_tail_rec(arr + 1, size - 1, key, counter);
}

//Ex 10 ###
void print_diag_2(char matrix[5][5]) {
  for (int i = 0; i < 5; i++) {
    cout << matrix[i][5 - 1 - i] << ' ';
  }
  cout << endl;
}

//Ex 11 ###
bool find_match(char str[], int len_str, char pattern[], int pattern_len) {
  bool found = false;
  for (int i = 0; i <= len_str - pattern_len && !found; i++) {
    bool is_match = true;
    int pattern_index = 0;
    for (int j = 0; j < pattern_len && is_match; j++) {
      if (pattern[j] != str[i + j]) {
	is_match = false;
      }
    }
    if (is_match) {
      found = true;
    }
  }

  return found;
}

//Ex 12 ###
bool are_rows_equal(int matrix[][4], int num_rows, int row_1, int row_2) {
  bool result = true;
  if (row_1 < 0 || row_1 > num_rows - 1 || row_2 < 0 || row_2 > num_rows - 1) {
    result = false;
  }
  else {
    for (int i = 0; i < 4 && result; i++) {
      if (matrix[row_1][i] != matrix[row_2][i]) {
	result = false;
      }
    }
  }

  return result;
}

//Ex 12 ###
bool are_columns_equal(int matrix[][4], int num_rows, int col_1, int col_2) {
  bool result = true;
  if (col_1 < 0 || col_1 > 3 || col_2 < 0 || col_2 > 3) {
    result = false;
  }
  else {
    for (int i = 0; i < num_rows && result; i++) {
      if (matrix[i][col_1] != matrix[i][col_2]) {
	result = false;
      }
    }
  }

  return result;
}

//Ex 13 ###
bool are_matrices_equal(int matrix1[][6], int matrix2[][6], int num_rows) {
  bool eq = true;
  for (int i = 0; i < num_rows && eq; i++) {
    for (int j = 0; j < 6 && eq; j++) {
      if (matrix1[i][j] != matrix2[i][j]) {
	eq = false;
      }
    }
  }

  return eq;
}

//Ex 15 ###
bool is_palindrome_rec(char* str, int l, int h) {
  //an empty string is palindrome
  if (l > h) {
    return true;
  }
  //opposite items are different, str cannot be palindrome
  if (str[l] != str[h]) {
    return false;
  }
  return is_palindrome_rec(str, l + 1, h - 1);
}

bool is_palindrome_iter_1(char* str, unsigned int size) {
  int l = 0, h = size - 1;
  while (l <= h) {
    if (str[l] != str[h]) {
      return false;
    }
    l++;
    h--;
  }

  return true;
}

bool is_palindrome_iter_2(char* str, unsigned int size) {
  int l = 0, h = size - 1;
  bool is_pal = true;
  while (l <= h && is_pal) {
    if (str[l] != str[h]) {
      is_pal = false;
    }
    l++;
    h--;
  }

  return is_pal;
}

int main() {
  char str[] = "radar";
  cout << is_palindrome_rec(str, 0, strlen(str) - 1) << endl;
  cout << is_palindrome_iter_1(str, strlen(str)) << endl;
  cout << is_palindrome_iter_2(str, strlen(str)) << endl;

  int matr1[][6] = {
    {0, 3, 6, 7, 3, 5},
    {34, 36, 34, 67, 72, 12},
    {34, 88, 120, 124, 166, 51},
    {5, 54, 36, 130, 240, 98},
    {-12, 1, 7, 40, 40, 53},
    {8, 9, 9, 17, 65, 16}
  };

  int matr2[][6] = {
    {0, 3, 6, 7, 3, 5},
    {34, 36, 34, 67, 72, 12},
    {34, 88, 120, 124, 166, 51},
    {5, 54, 36, 130, 240, 98},
    {-12, 1, 7, 40, 40, 53},
    {8, 9, 9, 17, 65, 16}
  };
}
