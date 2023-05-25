#include <iostream>
#include <climits>
using namespace std;

int main() {
  int counter_7 = 0;
  for (int num = 1; num <= 100; num++) {
    cout << num << endl;
    if(num / 10 == 7) {
      counter_7++;
    }
    if (num % 10 == 7) {
      counter_7++;
    }
  }

  cout << "digit 7 occurs " << counter_7 << " times between 1 and 100" << endl;
}
