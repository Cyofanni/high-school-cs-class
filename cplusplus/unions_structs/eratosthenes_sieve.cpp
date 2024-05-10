#include <iostream>
using namespace std;

#define LAST_NUM 1000000
#define SIEVE_SIZE LAST_NUM - 1

typedef struct nat_p_c {
  unsigned int number;
  bool is_prime;
} NUMBER_MARKER;

void print_number_marker(NUMBER_MARKER& n) {
  cout << "{" << endl;
  cout << "  number: " << n.number << endl;
  cout << "  primality: ";
  if (n.is_prime == true) {
    cout << "prime" << endl;
  }
  else {
    cout << "composite" << endl;
  }
  cout << "}" << endl;
}

int main() {
  NUMBER_MARKER nums[SIEVE_SIZE];
  for (unsigned int i = 2; i <= LAST_NUM; i++) {
    nums[i - 2].number = i;
    nums[i - 2].is_prime = true;
  }

  for (unsigned int i = 0; i < SIEVE_SIZE; i++) {
    for (unsigned int j = i + 2 * nums[i].number; j < SIEVE_SIZE;
         j += nums[i].number) {
    	nums[j].is_prime = false;
    }
  }

  for (unsigned int i = 0; i < SIEVE_SIZE; i++) {
    if (nums[i].is_prime) {
      print_number_marker(nums[i]);
    }
  }
}
