#include <stdio.h>

//https://en.wikipedia.org/wiki/File:International_Morse_Code.svg

int main() {
  char c;
  while (c = getchar()) {
    switch (c) {
    case 'a':
      puts("._");
      break;
    case 'b':
      puts("_...");
      break;
    case 'c':
      puts("_._.");
      break;
    case 'd':
      puts("_..");
      break;
    case 'e':
      puts(".");
      break;
    case 'f':
      puts("__._");
      break;
    case 'g':
      puts("__.");
      break;
    case 'h':
      puts("....");
      break;
    }
  }
}
