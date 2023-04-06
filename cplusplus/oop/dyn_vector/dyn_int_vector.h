class dyn_int_vector {
private:
  int *ptr;
  int size;
public:
  dyn_int_vector(int size, int val);
  ~dyn_int_vector();
};
