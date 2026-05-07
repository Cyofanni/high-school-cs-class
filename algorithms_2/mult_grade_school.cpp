#include <iostream>
using namespace std;

int mult(int* n1, int* n2, int sz) {
  int res = 0;
  int pow_10 = 1;

  int* res_tmp_arr = new int[sz];
  for (int i = sz - 1; i >= 0; i--) {
    int res_tmp_num = 0;
    for (int j = sz - 1; j >= 0; j--) {
      res_tmp_arr[j] = n2[i] * n1[j];
    }
    int mult = 1;
    for (int j = sz - 1; j >= 0; j--) {
      res_tmp_num += res_tmp_arr[j] * mult;
      mult = mult * 10;
    }
    res_tmp_num = res_tmp_num * pow_10;
    res = res + res_tmp_num;
    pow_10 = pow_10 * 10;
  }

  delete[] res_tmp_arr;
  return res;
}

int main() {
  int n1[] = {4, 4, 6, 9};
  int n2[] = {7, 6, 7, 3};
  cout << 4469 * 7673 << endl;
  cout << mult(n1, n2, 4) << endl;
}
