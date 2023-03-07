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
    cout << vect[i] << ' ';
  }
  cout << endl;

  int max = vect[0], min = vect[0], index_max = 0, index_min = 0;

  for (int i = 0; i < 10; i++) {
    if (vect[i] > max) {
      max = vect[i];
      index_max = i;
    }
    if (vect[i] < min) {
      min = vect[i];
      index_min = i;
    }
  }

  //swap
  int t = vect[index_max];
  vect[index_max] = vect[index_min];
  vect[index_min] = t;
  for (int i = 0; i < 10; i++) {
    cout << vect[i] << ' ';
  }
  cout << endl;
}
