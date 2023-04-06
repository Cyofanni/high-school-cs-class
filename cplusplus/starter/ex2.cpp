#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "enter an integer: ";
  cin >> num;

  cout << "even number less than " << num << " are: " << endl;
  for (int even_number = 0; even_number < num; even_number = even_number + 2) {
    cout << even_number << '\t';
  }
  cout << '\n';
}
