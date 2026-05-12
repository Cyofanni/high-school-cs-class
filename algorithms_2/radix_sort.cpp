#include <iostream>
#include <cmath>
using namespace std;

int get_digit(int num, int digit) {
  for (int i = 0; i < digit; i++) {
    num = num / 10;
  }
  return num % 10;
}

//sort by given digit (0 for LSD)
int* counting_sort(int* nums, int size, int digit) {
  int* nums_sorted = new int[size];
  int count[10] = {};

  //loop over nums
  for (int i = 0; i < size; i++) {
    int x = get_digit(nums[i], digit);
    count[x]++;
  }
  //loop over count
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    int x = nums[i];
    int y = get_digit(x, digit);
    int z = count[y];
    nums_sorted[z - 1] = x;
    count[y]--;
  }

  return nums_sorted;
}

void print_array(int* ar, int size) {
  for (int i = 0; i < size; i++) {
    cout << ar[i] << ' ';
  }
  cout << endl;
}

int main() {
  int numbers[] = {4597, 3361, 9841, 9849, 902, 1803, 8892, 6478, 7360, 4387, 362};
  int* part_sorted = numbers;
  for (int d = 0; d < 4; d++) {
    part_sorted = counting_sort(part_sorted, 11, d);
    print_array(part_sorted, 11);
    cout << endl;
  }
}
