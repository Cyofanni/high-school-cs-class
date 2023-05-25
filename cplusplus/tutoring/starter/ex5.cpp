#include <iostream>
#include <climits>
using namespace std;


int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;
  if (num >= 10 && num <= 20) {
    for (int i = num; i >=0; i--) {
      cout << i << ' ';
    }
  }
  cout << endl;
}
