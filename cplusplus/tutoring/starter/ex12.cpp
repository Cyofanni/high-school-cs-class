#include <iostream>
#include <climits>
using namespace std;

int main() {
  int n, m;
  cout << "enter two integers: ";
  cin >> n >> m;
  int product = 0;
  if (n > 0 && m > 0) { 
    for (int counter = 1; counter <= m; counter++) {
      product = product + n;
    }
  }
  cout << "the product is: " << product << endl;
}
