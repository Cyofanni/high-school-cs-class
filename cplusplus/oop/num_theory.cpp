#include <iostream>
#include <iomanip>
using namespace std;

class integer {
  friend ostream& operator<<(ostream&, const integer&);
  private:
    long int i;
  public:
    integer(long int i): i(i) {}

    long int get_i() const {
      return i;
    }

    bool is_prime() const {
      bool res = true;
      if (i == 1 || (i % 2 == 0 && i != 2)) {
        res = false;
      }
      for (int d = 3; d <= sqrt_() && res; d += 2) {
        if (i % d == 0) {
          res = false;
        }
      }
      return res;
    }

    void factorize() const {
      long int n = i;
      if (n == 0) {
        return;
      }
      while (n != 1) {
        bool f = false;
        for (int d = 2; d <= n && !f; d++) {
          if (n % d == 0) {
            f = true;
            cout << d << ' ';
            n = n / d;
          }
        }
      }
      cout << endl;
    }

    long double sqrt_() const {
      if (!i) {
        return 0;
      }
      double x = (double) i / 2;
      for (int j = 1; j <= 16; j++) {
        x = (x + i / x) / 2;
      }
      return x;
    }

    integer gcd_euclid(const integer& i1) const {
      long int a = i, b = i1.i;
      while (b) {
        long int r = a % b;
        a = b;
        b = r;
      }
      return integer(a);
    }

    integer phi_euler() const {
      unsigned long int count = 0;
      for (int j = 1; j < i; j++) {
        if (gcd_euclid(j).i == 1) {
          count++;
        }
      }
      return integer(count);
    }
};

ostream& operator<<(ostream& o, const integer& i) {
  o << i.i;
  return o;
}

int main() {
  integer i1(3);
  cout << setprecision(16) << i1.sqrt_() << endl;
  for (int i = 0; i <= 100; i++) {
    cout << i << "    " << integer(i).phi_euler().get_i() << endl;
  }
  integer(1024).factorize();
  integer i2(13), i3(16);
  cout << i2 << endl << i3 << endl;
}
