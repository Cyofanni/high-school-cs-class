#include "operation_poly.h"

operation::operation(int op1, int op2) {
  this -> op1 = op1;
  this -> op2 = op2;
}

int operation::get_op1() {
  return op1;
}

int operation::get_op2() {
  return op2;
}

addition::addition(int op1, int op2): operation(op1, op2) {
}

int addition::exec() {
  return get_op1() + get_op2();
}

multiplication::multiplication(int op1, int op2): operation(op1, op2) {
}

int multiplication::exec() {
  return get_op1() * get_op2();
}
