#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
  char state = 'A';
  uint8_t coin;
  bool accepted = false;

  while (!accepted) {
    scanf("%hhu", &coin);
    if (state == 'A') {
      if (coin == 1) {
        state = 'B';
      }
      else if (coin == 2) {
        state = 'C';
      }
      else if (coin == 5) {
        state = 'F';
        accepted = true;
      }
      else {
        printf("%s\n", "coin not accepted...");
      }
    }
    else if (state == 'B') {
      if (coin == 1) {
        state = 'C';
      }
      else if (coin == 2) {
        state = 'D';
      }
      else {
        printf("%s\n", "coin not accepted...");
      }
    }
    else if (state == 'C') {
      if (coin == 1) {
        state = 'D';
      }
      else if (coin == 2) {
        state = 'E';
      }
      else {
        printf("%s\n", "coin not accepted...");
      }
    }
    else if (state == 'D') {
      if (coin == 1) {
        state = 'E';
      }
      else if (coin == 2) {
        state = 'F';
        accepted = true;
      }
      else {
        printf("%s\n", "coin not accepted...");
      }
    }
    else if (state == 'E') {
      if (coin == 1) {
        state = 'F';
        accepted = true;
      }
      else {
        printf("%s\n", "coin not accepted...");
      }
    }
  }

  printf("%s\n", "starting to dispense...");
}
