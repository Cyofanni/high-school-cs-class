#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) {
  return a >= b ? a : b;
}

//O(n^3)
int max_sa_sum_3(int ar[], int size) {
  int max_sum = INT_MIN;

  for (int i = 0; i <= size - 1; i++) {
    for (int j = i; j <= size - 1; j++) {
      int curr_sum = 0;
      for (int k = i; k <= j; k++) {
        curr_sum += ar[k];
      }
      max_sum = max(curr_sum, max_sum);
    }
  }

  return max_sum;
}

//O(n^2)
int max_sa_sum_2(int ar[], int size) {
  int max_sum = INT_MIN;

  for (int i = 0; i <= size - 1; i++) {
    int curr_sum = 0;
    for (int j = i; j <= size - 1; j++) {
      curr_sum += ar[j];
      max_sum = max(curr_sum, max_sum);
    }
  }

  return max_sum;
}

//O(n)
int max_sa_sum_kadane(int ar[], int size) {
  int max_sum = INT_MIN;
  int curr_sum = 0;

  for (int i = 0; i < size; i++) {
    curr_sum = max(ar[i], curr_sum + ar[i]);
    max_sum = max(curr_sum, max_sum);
  }

  return max_sum;
}

int main() {
  int v[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << max_sa_sum_3(v, 8) << endl;
  cout << max_sa_sum_2(v, 8) << endl;
  cout << max_sa_sum_kadane(v, 8) << endl;
}
