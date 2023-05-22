#include <iostream>
using namespace std;

bool is_even(int x) {
  return x % 2 == 0;
}

bool is_odd(int x) {
  return x % 2 == 1;
}

void filter(bool (*pred) (int), int ls[], int size) {
  for (int i = 0; i < size; i++) {
    if ((*pred)(ls[i])) {
      cout << ls[i] << endl;
    }
  }
}

int main() {
  int lst[] = {45, 3, 27, 1, 2, 7, 6, 56, 24};
  filter(&is_even, lst, 9);
  cout << endl;
  filter(&is_odd, lst, 9);
}
