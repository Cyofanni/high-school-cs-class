#include <iostream>
#include <climits>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;

  int sum = 0;

  for (int i = 0; i <= num; i++) {
    sum = sum + i;
  }

  cout << "the sum is: " << sum << endl;
}
