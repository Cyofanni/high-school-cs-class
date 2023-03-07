#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int vect[10];

  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    vect[i] = rand() % 50;
  }

  int pivot_index = rand() % 10;
  int pivot = vect[pivot_index];

  for (int i = 0; i < 10; i++) {
    cout << vect[i] << ' ';
  }
  cout << endl;

  cout << "index of pivot is: " << pivot_index << endl;
  cout << "pivot is: " << pivot << endl << endl;

  for (int j = 0; j <= 9; j++) {
    if (pivot_index > j) {
      if (vect[j] > pivot) {
	for (int i = pivot_index; i > j; i--) {
	  vect[i] = vect[i - 1];
	}
	vect[j] = pivot;
	pivot_index = j;
      }
    }
    else if (pivot_index < j){
      if (vect[j] < pivot){
	int item = vect[j];
	for (int i = j; i > pivot_index; i--) {
	  vect[i] = vect[i - 1];
	}
	vect[pivot_index] = item;
	pivot_index++;
      }
    }
  }
  cout << endl;

  for (int i = 0; i < 10; i++) {
    cout << vect[i] << ' ';
  }
  cout << endl;
}
