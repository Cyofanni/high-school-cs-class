#include <iostream>
#include <climits>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;

  while (num != 0) {
    int sum_of_odd_numbers = 0;
    int current_odd_number = 1;
    for (int count = 1; count <= num; count++) {
      sum_of_odd_numbers = sum_of_odd_numbers + current_odd_number;
      current_odd_number += 2;
    }

    if (num * num == sum_of_odd_numbers) {
      cout << "verified" << endl;
    }
    else {
      cout << "not verified" << endl;
    }

    cout << "enter an integer: ";
    cin >> num;
  }
}
