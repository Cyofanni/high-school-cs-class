#include <stdio.h>

unsigned long ackermann(int x, int y) {
  if (x == 0) {
    return y + 1;
  }
  if (y == 0) {
    return ackermann(x - 1, 1);
  }
  return ackermann(x - 1, ackermann(x, y - 1));
}

int main(int argc, char* argv[]) {
  printf("%lu\n", ackermann(4, 2));
}
