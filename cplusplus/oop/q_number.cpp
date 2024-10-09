#include <iostream>
using namespace std;

class q_number {
  private:
    int num, den;
    int gcd() const;
  public:
    q_number();
    q_number(int, int);
    void reduce();
    void print() const;
};

q_number::q_number() {
}

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
  cout << num << '/' << den;
}

int main(int argc, char* argv[]) {
  const int matr_size = 8;
  q_number matr[matr_size][matr_size];

  for (int i = 0; i < matr_size; i++) {
    for (int j = 0; j < matr_size; j++) {
      matr[i][j] = q_number(i + 1, j + 1);
    }
  }
  for (int i = 0; i < matr_size; i++) {
    for (int j = 0; j < matr_size; j++) {
      matr[i][j].print();
      cout << ' ';
    }
    cout << endl;
  }
  cout << endl;

  int row = 0, col = 0;
  int n = 1;

  while (true) {
    matr[row][col].print();
    cout << "    ";

    //down
    row++;
    matr[row][col].print();
    cout << "    ";

    //diag up
    row--;
    col++;
    while (row >= 0) {
      matr[row][col].print();
      cout << "    ";
      row--;
      col++;
    }
    row++;
    col--;

    if (col == matr_size - 1) {
      break;
    }

    //right
    col++;
    matr[row][col].print();
    cout << "    ";

    //diag down
    row++;
    col--;
    while (col > 0) {
      matr[row][col].print();
      cout << "    ";
      row++;
      col--;
    }

    cout << endl;
  }

  cout << endl;
}
