#include <iostream>
#include <climits>
using namespace std;


int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;
  int min = INT_MAX; //the largest INT, any number is <= INT_MAX
  int input;

  for (int i = 1; i <= num; i++) {
    cin >> input;
    //if current input is less than minimum, the new minimum is input
    if (input < min) {
      min = input;
    }
  }

  cout << "the minimum value read from standard input is: " << min << endl;
}
