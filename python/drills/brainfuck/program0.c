#include <stdio.h>
int main() {
  int data[30000] = {0};
  int data_pointer = 0;
  data[data_pointer]++;
  loop_0:
    if (data[data_pointer] == 0) {
      goto end_loop_0;
    }
  if (data[data_pointer] != 0) {
    goto loop_0;
  }
  end_loop_0:
    ;
  return 0;
}
