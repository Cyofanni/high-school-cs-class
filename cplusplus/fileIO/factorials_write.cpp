#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream ofs("factorials_o");
  ofs << 0 << '\t' << 1 << endl;
  ofs << 1 << '\t' << 1 << endl;
  ofs << 2 << '\t' << 2 << endl;
  ofs << 3 << '\t' << 6 << endl;
  ofs << 4 << '\t' << 24 << endl;
  ofs << 5 << '\t' << 120 << endl;
}
