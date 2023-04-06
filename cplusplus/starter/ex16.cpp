#include <iostream>
#include <climits>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;
  for (int mult = 1; mult <= 12; mult++) {
    cout << num * mult << endl;
  }
}
