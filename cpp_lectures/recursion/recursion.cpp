#include <iostream>
#include <climits>
#include <chrono>
#include <cstring>

using namespace std;

void bad_rec_func() {
  if (0 == 1) {
    return;
  }
  return bad_rec_func();
}

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

int main() {
  /*
  auto t0 = chrono::high_resolution_clock::now();
  char algo_version[30];
  int choice = atoi(argv[1]);

  switch(choice){
  case 0:
    cout << natural_iterative(atoi(argv[2])) << endl;
    strncpy(algo_version, "iterative implementation:  ", strlen("iterative implementation:  ") + 1);
    break;
  case 1:
    cout << natural_recursive(atoi(argv[2])) << endl;
    strncpy(algo_version, "recursive implementation:  ", strlen("recursive implementation:  ") + 1);
    break;
  }

  auto t1 = chrono::high_resolution_clock::now();
  cout << algo_version << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanoseconds passed\n";
  */

  return 0;
}
