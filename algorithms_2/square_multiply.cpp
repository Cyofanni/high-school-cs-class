#include <iostream>
using namespace std;

//recursive square and multiply
int sq_mult(int b, int e[], int sz_e) {
  if (sz_e == 0) {
    return 1;
  }
  if (sz_e == 1) {
    if (*e == 0) {
      return 1;
    }
    else {
      return b;
    }
  }
  int r = sq_mult(b, e, sz_e - 1);
  if (e[sz_e - 1] == 0) {
    return r * r;
  }
  return b * r * r;
}

int main() {
  int e[] = {1, 0, 0, 1, 1};
  cout << sq_mult(3, e, 5) << endl;
}
