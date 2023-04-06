#include <iostream>
using namespace std;

//what happens?
unsigned int i = 0;
char str[8];

int main() {
  char c;
  cin >> c;
  if (c == 'q') {
    return 0;
  }
  str[i] = c;
  cout << i << endl;
  i++;
  return main();
}
