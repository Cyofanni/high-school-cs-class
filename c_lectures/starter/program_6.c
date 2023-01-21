/*
  The program reads 3 integers from stdin and prints 
  the greatest one stdout.
*/

#include <stdio.h>

int main() {
  int i, j, k;
  int max;
  printf("enter an integer: ");
  scanf("%d", &i);
  max = i;

  printf("enter an integer: ");
  scanf("%d", &j);
  if (j > max) {
    max = j;
  }
  printf("enter an integer: ");
  scanf("%d", &k);
  if (k > max) {
    max = k;
  }

  printf("the maximum value read from stdin is: %d\n", max);

  return 0;
}
