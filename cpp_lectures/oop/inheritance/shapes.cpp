#include <iostream>
using namespace std;

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
  virtual void draw() const {
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
  }
};

class line: public shape {
private:
  int size;
public:
  line(int size) {
    this->size = size;
  }
  virtual void draw() const {
    for (int i = 1; i <= size; i++) {
      cout << '*';
    }
    cout << endl;
  }
};

class chessboard: public shape {
private:
  int size;
public:
  chessboard(int size) {
    this->size = size;
  }
  virtual void draw() const {
    for (int i = 1; i <= size; i++) {
      if (i % 2) {
	cout << ' ';
      }
      for (int j = 1; j <= size; j++) {
	cout << '*';
      }
      cout << endl;
    }
    cout << endl;
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
  line l(18);
  chessboard cb(14);

  do_graphics(sq);
  do_graphics(l);
  do_graphics(cb);
  do_graphics(chessboard(7));
  do_graphics(&sq);
  do_graphics(&l);
  do_graphics(&cb);
}
