#include <iostream>
#include <cmath>
using namespace std;

//ex 4
bool is_prime(int n) {
  bool ans = true;
  if (n % 2 == 0 && n != 2 || n == 1) {
    ans = false;
  }
  else {
    for (int div = 3; div <= floor(sqrt(n)) && ans == true; div += 2) {
      if (n % div == 0) {
        ans = false;
      }
    }
  }

  return ans;
}

//ex 7a
int min_prime_sup(int n) {
  int i = 0, res = -1;
  bool found = false;

  while (found == false) {
    if (i > n && is_prime(i)) {
        res = i;
        found = true;
    }
    i++;
  }

  return res;
}

int main() {
}
