#include <iostream>
#include <climits>
#include <chrono>
#include <cstring>

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

int main(int argc, char *argv[]) {
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

  return 0;
}
