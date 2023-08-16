class operation {
  private:
    int op1;
    int op2;
  public:
    operation(int, int);
    virtual int exec() const = 0;
    int get_op1() const;
    int get_op2() const;
};

class addition: public operation {
  public:
    addition(int, int);
    int exec() const;
};

class multiplication: public operation {
  public:
    multiplication(int, int);
    int exec() const;
};
