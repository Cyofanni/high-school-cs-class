#include <iostream>
#include <climits>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;

  if (num >= 1 && num <= 20) {
    for (int i = 1; i <= num; i++) { //for each number between 1 and num
      for (int j = 1; j <= 10; j++) {
	cout << i * j << ' '; //print times table of the number
      }
      cout << endl;
    }
  }
}
