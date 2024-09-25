#include <stdio.h>

#define PARK_SIZE 5

int main() {
  char input;
  unsigned int n_cars = 0;

  while (1) {
    scanf(" %c", &input);
    if (input == 'I') {
      if (n_cars < PARK_SIZE) {
        n_cars++;
      }
      else {
        printf("%s\n", "park is full");
      }
    }
    else if (input == 'O') {
      if (n_cars > 0) {
        n_cars--;
      }
      else {
        printf("%s\n", "park is empty");
      }
    }
    else {
      printf("%s\n", "input not accepted, exiting program...");
      break;
    }
    printf("park has %d free slots\n", PARK_SIZE - n_cars);
  }
}
