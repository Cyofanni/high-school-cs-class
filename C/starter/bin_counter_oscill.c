#include <stdio.h>

int main(int argc, char* argv[]) {
  int n = 5;
  int b0 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  for (int i = 1; i <= 32; i++) {
    printf("%d: ",  i - 1);
    if (i <= 10) {
      putchar(' ');
    }
    printf("%d%d%d%d%d\n", b4, b3, b2, b1, b0);
    b0 = 1 - b0;
    if (i % 2 == 0) {
      b1 = 1 - b1;
    }
    if (i % 4 == 0) {
      b2 = 1 - b2;
    }
    if (i % 8 == 0) {
      b3 = 1 - b3;
    }
    if (i % 16 == 0) {
      b4 = 1 - b4;
    }
  }
}
