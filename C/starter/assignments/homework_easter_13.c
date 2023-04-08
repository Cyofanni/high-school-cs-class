#include <stdio.h>

int main() {
  int decimal_number;
  printf("enter an integer: ");
  scanf("%d", &decimal_number);
  do {
    int remainder = decimal_number % 16;
    if (remainder % 16 < 10) {
      printf("%d", remainder);
    }
    else if (remainder == 10) {
      printf("%c", 'A');
    }
    else if (remainder == 11) {
      printf("%c", 'B');
    }
    else if (remainder == 12) {
      printf("%c", 'C');
    }
    else if (remainder == 13) {
      printf("%c", 'D');
    }
    else if (remainder == 14) {
      printf("%c", 'E');
    }
    else {
      printf("%c", 'F');
    }

    decimal_number /= 16;
  } while (decimal_number != 0);

  putchar('\n');
}
