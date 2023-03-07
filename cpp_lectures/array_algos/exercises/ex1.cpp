#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    vect[i] = rand() % 50;
  }
  for (int i = 0; i < 10; i++) {
    cout << vect[i] << '\t' << vect[i] * vect[i] << endl;
  }
}
