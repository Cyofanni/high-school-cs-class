typedef enum {
  ADD_OP,
  MUL_OP
} op_type;

typedef struct operation{
  op_type t;
  int operand1;
  int operand2;
  int (*execute_op) (struct operation*);
} operation;

int execute_op(operation *);
