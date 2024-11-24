//https://leetcode.com/problems/nim-game/
#include <stdio.h>
#include <stdbool.h>

void print_heaps(int h1, int h2, int h3) {
  puts("HEAPS:\n");
  printf("A    ");
  for (int i = 1; i <= h1; i++) {
    putchar('*');
  }
  putchar('\n');
  printf("B    ");
  for (int i = 1; i <= h2; i++) {
    putchar('*');
  }
  putchar('\n');
  printf("C    ");
  for (int i = 1; i <= h3; i++) {
    putchar('*');
  }
  putchar('\n');
}

void print_player_name(int player) {
  if (player == 1) {
    printf("Bob");
  }
  else if (player == -1) {
    printf("Alice");
  }
}

int main() {
  int heap_A = 3, heap_B = 4, heap_C = 5;
  int player = 1;

  while (heap_A > 0 || heap_B > 0 || heap_C > 0) {
    print_heaps(heap_A, heap_B, heap_C);

    putchar('\n');
    print_player_name(player);
    printf("\'s turn, ");
    printf("choose heap (A, B, or C): ");
    char heap;
    int num_matches;
    scanf(" %c", &heap);
    printf("choose number of matches: ");
    scanf("%d", &num_matches);

    switch (heap) {
      case 'A':
        heap_A -= num_matches;
      break;
      case 'B':
        heap_B -= num_matches;
      break;
      case 'C':
        heap_C -= num_matches;
      break;
    }

    player = -player;
    putchar('\n');
  }

  int winner = -player;
  printf("the winner is: ");
  print_player_name(winner);
  putchar('\n');
}
