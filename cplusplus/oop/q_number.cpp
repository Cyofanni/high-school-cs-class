#include <iostream>
using namespace std;

class q_number {
  private:
    int num, den;
    int gcd() const;
  public:
    q_number(int, int);
    void reduce();
    void print() const;
};

q_number::q_number(int num, int den): num(num), den(den) {
}

int q_number::gcd() const {
  int a = num, b = den;
  while (b != 0) {
    int rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

void q_number::reduce() {
  int res = gcd();
  if (res == 1) {
    return;
  }
  num = num / res;
  den = den / res;
}

void q_number::print() const {
  cout << num << '/' << den << endl;
}

int main(int argc, char* argv[]) {
  q_number q1(20, 15);
  q1.print();
  q1.reduce();
  q1.print();
}
