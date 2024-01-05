#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream ifs("factorials_i");
  int n, f;
  while (ifs >> n >> f) {
    cout << n << ' ' << f << endl;
  }
}
