#include <iostream>
using namespace std;

//abstract class
class shape {
public:
  virtual void draw() const = 0;
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
};

void do_graphics(const shape* s) {
  s -> draw();
  cout << endl << endl;
}

int main() {
  square sq(6);
  sq.draw();
  line l(13);
  l.draw();
  chessboard cb(10);

  shape* s = &sq;
  s -> draw();
  s = &l;
  s -> draw();
  s = &cb;
  s -> draw();
}
