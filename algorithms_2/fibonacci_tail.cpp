#include <iostream>
using namespace std;

int fibonacci(int n) {
  int f0 = 0, f1 = 1, f2;

  if (n == 0) {
    return f0;
  }
  if (n == 1) {
    return f1;
  }

  for (int i = 2; i <= n; i++) {
    f2 = f0 + f1;
    f0 = f1;
    f1 = f2;
  }

  return f2;
}

int fibonacci_tr_1(int n, int f0, int f1, int f2, int i) {
  if (n == 0) {
    return f0;
  }
  if (n == 1) {
    return f1;
  }

  if (i == n + 1) {
    return f2;
  }

  f2 = f0 + f1;
  f0 = f1;
  f1 = f2;
  return fibonacci_tr_1(n, f0, f1, f2, i + 1);
}

int fibonacci_tr_2(int n, int f0, int f1, int f2, int i) {
  if (n == 0) {
    return f0;
  }
  if (n == 1) {
    return f1;
  }

  if (i == n + 1) {
    return f2;
  }

  return fibonacci_tr_2(n, f1, f0 + f1, f0 + f1, i + 1);
}

int fibonacci_tr_3(int n, int f0, int f1, int f2) {
  if (n == 0) {
    return f0;
  }
  if (n == 1) {
    return f2;
  }

  return fibonacci_tr_3(n - 1, f1, f0 + f1, f0 + f1);
}

int main() {
  for (int n = 0; n < 20; n++) {
    cout << fibonacci_tr_1(n, 0, 1, 1, 2) << '\t' << fibonacci_tr_2(n, 0, 1, 1, 2) << '\t' <<
      fibonacci_tr_3(n, 0, 1, 1) << endl;
  }
  cout << endl;
}
