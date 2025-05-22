#include <stdio.h>

int main() {
  char state = 'A';
  char inp;

  scanf(" %c", &inp);
  while (inp != 'q') {
    switch (state) {
      case 'A':
        if (inp == 'a') {
          state = 'B';
        }
        else if (inp == 'b') {
          state = 'A';
        }
        else {
          puts("input not accepted");
        }
      break;
      case 'B':
        if (inp == 'a' || inp == 'b') {
          state = 'A';
        }
        else {
          puts("input not accepted");
        }
      break;
    }
    scanf(" %c", &inp);
  }

  if (state == 'B') {
    puts("end of input string: ACCEPTED");
  }
  else {
    puts("end of input string: REJECTED");
  }
}
