#include <iostream>
#include <cmath>

using namespace std;

typedef struct number_prime_info {
  unsigned int n;
  bool is_mult;
} npi;

void sieve_of_eratosthenes(unsigned int n) {
  unsigned int array_size = n - 1;
  npi *numbers = new npi[n - 2];
  for (int i = 0; i < array_size; i++) {
    numbers[i].n = i + 2;
    numbers[i].is_mult = false;
  }

  for (int i = 0; numbers[i].n <= sqrt(n); i++) {
    for (int j = i + 1; j < array_size; j++) {
      if (!numbers[j].is_mult && (numbers[j].n % numbers[i].n == 0)) {
	numbers[j].is_mult = true;
      }
    }
  }

  for (int k = 0; k < array_size; k++) {
    cout << numbers[k].n << '\t';
    if (numbers[k].is_mult) {
      cout << "is not prime";
    }
    else {
      cout << "is prime";
    }
    cout << '\n';
  }

  delete[] numbers;
}

int main() {
  sieve_of_eratosthenes(3000);
}
