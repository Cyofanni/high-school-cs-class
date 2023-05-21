#include <iostream>
#include <cmath>
using namespace std;

class bad_area {
};

double area(int length, int width) {
  if (length <= 0 || width <= 0) {
    throw bad_area();
  }
  return length * width;
}

int main() {
  try {
    area(-4.0, 23);
  }
  catch (bad_area) {
    cout << "passed bad arguments to area" << endl;
  }
}
