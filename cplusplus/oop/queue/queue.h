class queue {
 private:
  int* ar;
  int capacity;
  int size;
  int head;
  int tail;
 public:
  queue(int);
  ~queue();
  bool is_full();
  bool is_empty();
  void enqueue(int);
  void dequeue();
  void print();
};

class queue_full_exception {
};

class queue_empty_exception {
};
