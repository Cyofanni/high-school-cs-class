#include <iostream>
using namespace std;

struct ee_triple {
  int d, x, y;
};

struct ee_triple ext_eucl(int a, int b) {
  if (b == 0) {
    return {a, 1, 0};
  }
  struct ee_triple t1;
  t1 = ext_eucl(b, a % b);
  struct ee_triple t;
  t.d = t1.d;
  t.x = t1.y,
  t.y = t1.x - (a / b) * t1.y;
  return t;
}

int main() {
  struct ee_triple tr = ext_eucl(235, 76);
  cout << tr.d << endl;
  cout << tr.x << endl;
  cout << tr.y << endl;
}
