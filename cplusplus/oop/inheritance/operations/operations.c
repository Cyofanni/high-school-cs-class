#include "operations.h"
#include <stdio.h>

int execute_op(operation *op) {
  int result;
  switch (op -> t) {
    case ADD_OP:
      result = op -> operand1 + op -> operand2;
    break;
    case MUL_OP:
      result = op -> operand1 * op -> operand2;
    break;
    default:
      result = -1;
  }

  return result;
}

int main() {
  operation o1 = {MUL_OP, 10, 3, &execute_op};
  int r = o1.execute_op(&o1);
  printf("%d\n", r);
}
