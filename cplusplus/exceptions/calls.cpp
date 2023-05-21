#include <iostream>
using namespace std;

class e {
};

void f() {
  throw e();
}

void g() {
  f();
}

void h() {
  try {
    g();
  }
  catch (e) {
    cout << "caught e" << endl;
  }
}

int main() {
  //try {
    h();
  //}
  //catch (e) {
  //  cout << "caught e" << endl;
  //}

  cout << "program continues..." << endl;
}
