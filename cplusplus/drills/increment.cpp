#include <iostream>
using namespace std;

class point {
private:
  double x, y;
public:
  point(double x, double y): x(x), y(y) {}
  point operator++(int) {
    point p(*this);
    this -> x++;
    this -> y++;
    return p;
  }
  point operator++() {
    this -> x++;
    this -> y++;
    return *this;
  }
  double get_x() const {
    return x;
  }
  double get_y() const {
    return y;
  }
};
 
int main(int argc, char* argv[]) {
  point p(8, 6);
  point p1 = p++;
  cout << p1.get_x() << '\t' << p1.get_y() << endl;
  cout << p.get_x() << '\t' << p.get_y() << endl;
  cout << endl;
  point q(8, 6);
  point q1 = ++q;
  cout << q1.get_x() << '\t' << q1.get_y() << endl;
  cout << q.get_x() << '\t' << q.get_y() << endl;
}
