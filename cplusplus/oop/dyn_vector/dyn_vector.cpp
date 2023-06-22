#include <iostream>
using namespace std;

class dyn_vector {
private:
  int* ptr;
  int size;
public:
  dyn_vector(int size, int val) {
    this -> size = size;
    this -> ptr = new int[size];
    for (int i = 0; i < size; i++) {
      this -> ptr[i] = val;
    }
  }
  dyn_vector(const dyn_vector& v) {
    this -> size = v.size;
    this -> ptr = new int[size];
    for (int i = 0; i < size; i++) {
      this -> ptr[i] = v[i];
    }
  }
  int& operator[](int i) const {
    return this -> ptr[i];
  }
  void print() const {
    for (int i = 0; i < size; i++) {
      cout << this -> ptr[i] << ' ';
    }
    cout << endl;
  }
  ~dyn_vector() {
    delete[] ptr;
  }
};

int main() {
  dyn_vector dv1(6, 12);
  dyn_vector dv2(dv1);
  dv1.print();
  dv1[0] = 13;
  dv1.print();
  dv2.print();
}
