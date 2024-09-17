#include <iostream>
#include <string>
using namespace std;

int count = 0;

void print_powerset(string set, int k, string curr) {
  if (k == set.size()) {
    cout << curr << endl;
    count++;
    return;
  }
  print_powerset(set, k + 1, curr);
  print_powerset(set, k + 1, curr + set.at(k));
}

int main() {
  print_powerset("abc", 0, "");
  cout << endl << count << endl;
}
