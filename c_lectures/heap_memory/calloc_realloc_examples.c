#include <stdio.h>
#include <stdlib.h>

void unsafe_heap_write() {
  size_t heap_ar_len = 4;
  int * const heap_ar = (int * const) calloc(heap_ar_len, sizeof(int));
  
  int in;
  printf("%s ", "enter an integer: ");
  scanf("%d", &in);
  int item_cnt = 0;
  
  while (in != -1) {
    heap_ar[item_cnt] = in;
    printf("%s ", "enter an integer: ");
    scanf("%d", &in);
    item_cnt++;
  }
  
  for (int j = 0; j < item_cnt; j++) {
    printf("%d\t", heap_ar[j]);
  }
  putchar('\n');

  free(heap_ar);
}

void safe_heap_write() {
  size_t heap_ar_len = 4;
  int * heap_ar = (int*) calloc(heap_ar_len, sizeof(int));
  printf("heap_ar allocated with size %lu at address %p\n", heap_ar_len, heap_ar);
   
  int in;
  printf("%s ", "enter an integer: ");
  scanf("%d", &in);
  int item_index = 0;
  
  while (in != -1) {
    if (item_index + 1 > heap_ar_len - 1) {
      heap_ar_len *= 2;
      printf("heap_ar allocated with size %lu at address %p\n", heap_ar_len, heap_ar);
      heap_ar = (int*) realloc(heap_ar, heap_ar_len * sizeof(int));
    }
    heap_ar[item_index] = in;
    printf("%s ", "enter an integer: ");
    scanf("%d", &in);
    item_index++;
  }
  
  for (int j = 0; j < item_index; j++) {
    printf("%d\t", heap_ar[j]);
  }
  putchar('\n');

  free(heap_ar);
}


int main() {
  safe_heap_write();
}
