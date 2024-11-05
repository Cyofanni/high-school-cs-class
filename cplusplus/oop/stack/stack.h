class stack {
 private:
  int* ar;
  int top;
  int capacity;
  int size;
 public:
  stack();
  stack(int);
  ~stack();
  bool is_full() const;
  bool is_empty() const;
  int get_size() const;
  void push(int);
  int pop();
  void print() const;
};

class stack_full_exception {
};

class stack_empty_exception {
};
