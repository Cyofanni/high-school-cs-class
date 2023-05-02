#include <stdio.h>

//https://en.wikipedia.org/wiki/File:International_Morse_Code.svg

int main() {
  char c;
  while ((c = getchar()) != EOF) {
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
    case 'i':
      puts("..");
      break;
    case 'j':
      puts(".___");
      break;
    case 'k':
      puts("_._");
      break;
    case 'l':
      puts("._..");
      break;
    case 'm':
      puts("__");
      break;
    case 'n':
      puts("_.");
      break;
    case 'o':
      puts("___");
      break;
    case 'p':
      puts(".__.");
      break;
    case 'q':
      puts("__._");
      break;
    case 'r':
      puts("._.");
      break;
    case 's':
      puts("...");
      break;
    case 't':
      puts("...");
      break;
    case 'u':
      puts(".._");
      break;
    case 'v':
      puts("..._");
      break;
    case 'w':
      puts(".__");
      break;
    case 'x':
      puts("_.._");
      break;
    case 'y':
      puts("_.__");
      break;
    case 'z':
      puts("__..");
      break;
    }
  }
}
