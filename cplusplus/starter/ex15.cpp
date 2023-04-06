#include <iostream>
#include <climits>
using namespace std;

int main() {
  int odd_number = 1;
  for (int odd_number_counter = 1; odd_number_counter <= 100; odd_number_counter++) {
    cout << odd_number << ' ';
    if (odd_number_counter % 5 == 0) {
      cout << endl;
    }
    odd_number += 2;
  }
}
