class stack {
 private:
  int* ar;
  int top;
  int capacity;
  int size;
 public:
  stack(int);
  bool is_full();
  bool is_empty();
  void push(int);
  void pop();
  void print();
};

class stack_full_exception {
};

class stack_empty_exception {
};
