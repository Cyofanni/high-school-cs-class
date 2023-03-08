#include <iostream>
#include <climits>

using namespace std;

int main() {
  int times[11] = {10, 12, 13, 15, 16, 19, 20, 21, 30, 40, INT_MAX};
  int new_time;
  cin >> new_time;

  int i;
  for (i = 0; i < 11 && new_time > times[i]; i++) {
  }

  for (int j = 10; j > i; j--) {
    times[j] = times[j - 1];
  }

  times[i] = new_time;
  for (int i = 0; i < 11; i++) {
    cout << times[i] << ' ';
  }
  cout << endl;
}
