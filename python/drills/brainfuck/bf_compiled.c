#include <stdio.h>
int main() {
  char data[30000] = {0};
  int data_pointer = 0;
  data[data_pointer]++;
  loop0:
    if (data[data_pointer] == 0) {
      goto end_loop0
    }
  if data[data_pointer] != 0 {
   goto loop0;
  }
  end_loop0
 return 0;
}
