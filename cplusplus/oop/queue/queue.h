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
  bool is_full() const;
  bool is_empty() const;
  void enqueue(int);
  void dequeue();
  void print() const;
};

class queue_full_exception {
};

class queue_empty_exception {
};
