#include <stdio.h>

void print_array(int* ar, int sz, int* choice) {
  for (int i = 0; i < sz; i++) {
    if (choice[i]) {
      printf("%d ", ar[i]);
    }
  }
  putchar('\n');
}

void powerset(int* set, int size, int i, int* subset) {
  if (i == size) {
    print_array(set, size, subset);
    return;
  }
  powerset(set, size, i + 1, subset);
  subset[i] = 1;
  powerset(set, size, i + 1, subset);
  subset[i] = 0;
}

int main() {
  int size = 4;
  int S[] = {1, 2, 3, 4};
  int c[] = {0, 0, 0, 0};
  powerset(S, size, 0, c);
}
