#include <stdio.h>
#include <limits.h>

/*display the one's complement of a hexadecimal number,
  using bitwise operator;
*/
int main() {
    unsigned short n;
    printf("enter an unsigned integer (hex): ");
    scanf("%hx", &n);
    printf("the ones complement is: %hx\n", ~n);

    printf("the sum is %hx\n", n + ~n);
}
