#include <iostream>
#include <climits>

using namespace std;

int main() {
  int num_binary_1[8] = {};
  int num_binary_2[8] = {};
  int sum_binary[8] = {};
  int num_dec_1, num_dec_2;
  cin >> num_dec_1;
  cin >> num_dec_2;
  if (num_dec_1 > 0 && num_dec_1 < 100 && num_dec_2 > 0 && num_dec_2 < 100) {
    int i = 7;
    do {
      num_binary_1[i] = num_dec_1 % 2;
      num_dec_1 /= 2;
      i--;
    } while (num_dec_1 != 0);

    i = 7;
    do {
      num_binary_2[i] = num_dec_2 % 2;
      num_dec_2 /= 2;
      i--;
    } while (num_dec_2 != 0);

    cout << ' ';
    for (int j = 0; j < 7; j++) {
      cout << num_binary_1[j];
    }
    cout << endl;
    cout << ' ';
    for (int j = 0; j < 7; j++) {
      cout << num_binary_2[j];
    }
    cout << endl;

    //binary sum, with carry
    int carry = 0;
    for (int j = 7; j >= 0; j--) {
      if (num_binary_1[j] == 0 && num_binary_2[j] == 0) {
	if (carry == 0) {
	  sum_binary[j] = 0;
	}
	else{
	  sum_binary[j] = 1;
	  carry = 0;
	}
      }
      else if (num_binary_1[j] == 0 && num_binary_2[j] == 1) {
	if (carry == 0) {
	  sum_binary[j] = 1;
	}
	else {
	  sum_binary[j] = 0;
	}
      }
      else if (num_binary_1[j] == 1 && num_binary_2[j] == 0) {
	if (carry == 0) {
	  sum_binary[j] = 1;
	}
	else {
	  sum_binary[j] = 0;
	}
      }
      else {
	if (carry == 0) {
	  sum_binary[j] = 0;
	  carry = 1;
	}
	else {
	  sum_binary[j] = 1;
	}
      }
    }
  }

  for (int j = 0; j < 8; j++) {
    cout << sum_binary[j];
  }
  cout << endl;
}
