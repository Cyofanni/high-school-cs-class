#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];
  int vect_less_eq[10] = {};
  int vect_greater[10] = {};
  int index_less_eq = -1, index_greater = -1;
  int x = 12;

  for (int i = 0; i < 10; i++) {
    cin >> vect[i];
  }

  for (int i = 0; i < 10; i++) {
    if (vect[i] <= x) {
      index_less_eq++;
      vect_less_eq[index_less_eq]= vect[i];
    }
    else {
      index_greater++;
      vect_greater[index_greater]= vect[i];
    }
  }
  cout << endl;


  for (int i = 0; i < 10; i++) {
    cout << vect_less_eq[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << vect_greater[i] << ' ';
  }
  cout << endl;
}
