#include <stdio.h>
int
main ()
{
  int data[30000] = { 0 };
  int data_pointer = 0;
  scanf ("%d", &data[data_pointer]);
  data_pointer++;
  scanf ("%d", &data[data_pointer]);
  data_pointer--;
  while (data[data_pointer])
    {
      data[data_pointer]--;
      data_pointer++;
      data[data_pointer]++;
      data_pointer--;
    }
  data_pointer++;
  printf ("%d", (data[data_pointer]));
  return 0;
}
