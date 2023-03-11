#include <stdio.h>

int main() {
  int dec_num;
  printf("enter a decimal number: ");
  scanf("%d", &dec_num);

  /*
    10 % 2: 0
     5 % 2: 1
     2 % 2: 0
     1 % 2: 1
     0
  */
  printf("binary conversion (reversed, while) is: ");
  if (!dec_num) {
    printf("%d", 0);
  }
  else {
    while (dec_num != 0) {
      printf("%d", dec_num % 2);
      dec_num /= 2;
    }
  }
  putchar('\n');

  printf("enter a decimal number: ");
  scanf("%d", &dec_num);
  printf("binary conversion (reversed, do-while) is: ");
  do {
    printf("%d", dec_num % 2);
    dec_num /= 2;
  } while (dec_num != 0);
  putchar('\n');
}
