#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;
  int sum = 0;
  int input;

  for (int i = 1; i <= num; i++) {
    cout << "enter a number: ";
    cin >> input;
    sum = sum + input;
  }

  cout << "the sum of the numbers read from standard input is: " << sum << endl;
}
