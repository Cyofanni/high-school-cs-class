#include <iostream>
#include <climits>
#include <chrono>
#include <cstring>
#include <cstdlib>

using namespace std;

unsigned long long natural_recursive(unsigned long long n) {
  return !n ? 0 : 1 + natural_recursive(n - 1);
}

unsigned long long natural_iterative(unsigned long long n) {
  unsigned long long result = 0;
  unsigned int c = 1;
  while (c++ <= n) {
    result += 1;
  }

  return result;
}

unsigned long long natural_nocalc(unsigned long long n) {
  return n;
}

unsigned long long fibonacci(unsigned int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  unsigned long long fib_n_1 = fibonacci(n - 1);
  unsigned long long fib_n_2 = fibonacci(n - 2);
  return fib_n_1 + fib_n_2;
}

void print_fibonacci_sequence(int pp/*0*/, int p/*1*/, int c, int i/*0*/, int count) {
    if (i == count) {
        cout << endl;
        return;
    }
    c = pp + p;
    cout << c << ' ';

    return print_fibonacci_sequence(p, c, c, i + 1, count);
}

int product_recursive(int n, int m) {
  if (n < 0 || m < 0) {
    return -999;
  }
  if (m == 0) {
    return 0;
  }
  return n + product_recursive(n, m - 1);
}

bool binary_search_iterative_not_structured(int a[], int size, int key) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int middle = (low + high) / 2;
    if (key == a[middle]) {
      return true;
    }
    else if (key < a[middle]) {
      high = middle - 1;
    }
    else {
      low = middle + 1;
    }
  }

  return false;
}

bool binary_search_recursive(int a[], int low, int high, int key) {
  if (low > high) {
    return false;
  }
  int middle = (low + high) / 2;
  if (key == a[middle]) {
    return true;
  }
  if (key < a[middle]) {
    return binary_search_recursive(a, low, middle - 1, key);
  }
  return binary_search_recursive(a, middle + 1, high, key);
}

int main() {
  int arr[12] = {1, 5, 6, 12, 13, 14, 16, 20, 21, 24, 25, 28};
  cout << binary_search_iterative_not_structured(arr, 12, 28) << endl;
  cout << binary_search_recursive(arr, 0, 11, 28) << endl;

  return 0;
}
