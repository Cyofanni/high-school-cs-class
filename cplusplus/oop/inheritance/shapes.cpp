#include <iostream>
using namespace std;

//abstract class
class shape {
public:
  int x;
  virtual void draw() const = 0;
  virtual void move() = 0;
  virtual int get_x() const = 0;
};

class square: public shape {
private:
  int size;
public:
  square(int size) {
    this->size = size;
  }
  void draw() const {
    for (int i = 1; i <= size; i++) {
      if (i == 1 || i == size) {
	for (int j = 1; j <= size; j++) {
	  cout << '*';
	}
	cout << endl;
      }
      else {
	cout << '*';
	for (int j = 1; j <= size - 2; j++) {
	  cout << ' ';
	}
	cout << '*' << endl;
      }
    }
    cout << endl << endl;
  }
  void move() {

  }
  int get_x() const {
    return x;
  }
};

class line: public shape {
private:
  int size;
public:
  line(int size) {
    this->size = size;
  }
  void draw() const {
    for (int i = 1; i <= size; i++) {
      cout << '*';
    }
    cout << endl << endl;
  }
  void move() {

  }
  int get_x() const {
    return x;
  }
};

class chessboard: public shape {
private:
  int size;
public:
  chessboard(int size) {
    this->size = size;
  }
  void draw() const {
    for (int i = 1; i <= size; i++) {
      if (i % 2) {
	cout << ' ';
      }
      for (int j = 1; j <= size; j++) {
	cout << '*';
      }
      cout << endl;
    }
    cout << endl << endl;
  }
  void move() {

  }
  int get_x() const {
    return x;
  }
};

void do_graphics(const shape& s) {
  s.draw();
  cout << endl << endl;
}

void do_graphics(const shape* s) {
  s->draw();
  cout << endl << endl;
}

int main() {
  square sq(6);
  sq.x = 10;
  line l(13);
  l.x = 20;

  /*
  shape* s = &sq;
  s->draw();
  s = &l;
  s->draw();
  */

  //example on integer reference
  int a = 10, b = 20;
  cout << "a: " << a << "  b: " << b << endl;
  int& ref = a;
  cout << "ref: " << ref << "  a: " << a << endl;
  cout << "address of ref: " << &ref << "  address of a: " << &a << endl;
  ref = b;
  cout << "ref: " << ref << "  b: " << b << endl;
  cout << "address of ref: " << &ref << "  address of b: " << &b << endl << endl;

  //note that address of reference does not change
  shape& sref = sq;
  cout << "sref.x: " << sref.x << "   sq.x: " << sq.x << endl;
  cout << "address of sref: " << &sref << "  address of sq: " << &sq << endl;
  cout << "sref.get_x(): " << sref.get_x() << "   sq.x: " << sq.x << endl;
  sref.draw();

  sref = l;
  cout << "sref.x: " << sref.x << "   l.x: " << l.x << endl;
  cout << "address of sref: " << &sref << "  address of l: " << &l << endl;
  cout << "sref.get_x(): " << sref.get_x() << "   l.x: " << l.x << endl;
  sref.draw();
}
