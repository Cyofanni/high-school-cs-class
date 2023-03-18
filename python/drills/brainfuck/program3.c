#include <stdio.h>
int main() {
  int data[30000] = {0};
  int data_pointer = 0;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  data[data_pointer]++;
  loop_0:
    if (data[data_pointer] == 0) {
      goto end_loop_0;
    }
 printf("%d", (data[data_pointer]));
  data_pointer++;
 scanf("%d", &data[data_pointer]);
  data_pointer--;
  data[data_pointer]--;
  if (data[data_pointer] != 0) {
    goto loop_0;
  }
  end_loop_0:
    ;
 printf("%d", (data[data_pointer]));
  return 0;
}
