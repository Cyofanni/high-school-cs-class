#include <stdio.h>

int main(int argc, char* argv[]) {
  char state = 'A';
  char next_char;

  while (state != 'C' && state != 'D' && state != 'E' &&
         state != 'F' && state != 'H' && state != 'I') {
    scanf(" %c", &next_char);
    switch (state) {
      case 'A':
        switch (next_char) {
          case '<':
            state = 'B';
          break;
          case '=':
            state = 'F';
            puts("EQ");
          break;
          case '>':
            state = 'G';
          break;
        }
      break;
      case 'B':
        switch (next_char) {
          case '=':
            state = 'C';
            puts("LE");
          break;
          case '>':
            state = 'D';
            puts("NE");
          break;
          default:
            state = 'E';
            puts("LT");
        }
      break;
      case 'G':
        switch (next_char) {
          case '=':
            state = 'H';
            puts("GE");
          break;
          default:
            state = 'I';
            puts("GT");
        }
      break;
    }
  }
}
