#include <iostream>
#include <cmath>
using namespace std;

double c2f(double deg_c) {
  return deg_c * 1.8 + 32;
}

double f2c(double deg_f) {
  return (deg_f - 32) * (0.55);
}

struct point {
  double x, y, z;
};

struct line {
  double a, b, c;
};

struct S {
  int x, y;
};

void swap_xor(int& a, int& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void insertion_sort_rec_S(struct S arr[], int size, int i) {
  if (i == size) {
    return;
  }
  int j = i - 1;
  struct S item = arr[i];
  while (j >= 0 && item.x < arr[j].x) {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = item;
  insertion_sort_rec_S(arr, size, i + 1);
}

double distance_3D(struct point& p1, struct point& p2) {
  return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2) +
	      pow((p1.z - p2.z), 2));
}

double distance_l_p(struct line* l_ptr, struct point* p_ptr) {
  double num = abs(l_ptr->a*p_ptr->x + l_ptr->b*p_ptr->y + l_ptr->c);
  double den = sqrt(pow(l_ptr->a, 2) + (l_ptr->b, 2));
  return num / den;
}

long int factorial(int n) {
  long int acc = 1;
  for (int i = n; i >= 2; i--) {
    acc *= i;
  }
  return acc;
}

long int bin_coeff(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

void coeffs_bin_power(double a, double b, int n) {
  for (int k = 0; k <= n; k++) {
    cout << bin_coeff(n, k) << '*' << a << '^' << (n - k)
	 << '*' << b << '^' << k << endl;
  }
}

int* erat_sieve(int num_max) {
  int size = num_max - 1;
  int* nums = new int[num_max - 1];
  for (int i = 0; i < size; i++) {
    nums[i] = i + 2;
  }

  for (int i = 0; i < size - 1; i++) {
    int num = nums[i];
    if (num >= 2) {
      for (int j = i + num; j < size; j += num) {
	nums[j] = 0;
      }
    }
  }

  return nums;
}

int main(int argc, char* argv[]) {
}
