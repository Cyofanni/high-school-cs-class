#include <iostream>
#include "operation_poly.h"

using namespace std;

int main() {
  addition a1(4, 5);
  cout << a1.exec() << endl;
  operation* o1 = &a1;
  cout << o1 -> exec() << endl;
  o1 = new multiplication(5, 6);
  cout << o1 -> exec() << endl;
}
