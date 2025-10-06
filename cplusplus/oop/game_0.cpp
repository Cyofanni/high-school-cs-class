#include <iostream>
#include <cstdlib>

using namespace std;

class cube {
private:
  int size;
  int ulc_x;  //ulc: upper left corner
  int ulc_y;
public:
  cube(int size, int ulc_x = 0, int ulc_y = 0) {
    this -> size = size;
    this -> ulc_x = ulc_x;
    this -> ulc_y = ulc_y;
  }

  int get_size() const {
    return size;
  }

  void set_size(int s) {
    this -> size = s;
  }

  void set_ulc_x(int x) {
    this -> ulc_x = x;
  }

  void set_ulc_y(int y) {
    this -> ulc_y = y;
  }

  void move_left() {
    this -> ulc_x--;
  }

  void move_right() {
    this -> ulc_x++;
  }

  void move_up() {
    this -> ulc_y--;
  }

  void move_down() {
    this -> ulc_y++;
  }

  void draw() const {
    for (int i = 0; i < ulc_y; i++) {
      cout << endl;
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < ulc_x; j++) {
        cout << ' ';
      }
      for (int j = 0; j < size; j++) {
        cout << '*';
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  cube c1(6, 1, 1);
  c1.draw();
  char command;

  while (true) {
    cout << "enter a move (L, R, D, U): ";
    cin >> command;
    switch (command) {
    case 'L':
      c1.move_left();
      system("clear");
      c1.draw();
      break;
    case 'R':
      c1.move_right();
      system("clear");
      c1.draw();
      break;
    case 'D':
      c1.move_down();
      system("clear");
      c1.draw();
      break;
    case 'U':
      c1.move_up();
      system("clear");
      c1.draw();
      break;
    }
  }
}
