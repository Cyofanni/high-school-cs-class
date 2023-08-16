class operation {
  private:
    int op1;
    int op2;
  public:
    operation(int, int);
    virtual int exec() = 0;
    int get_op1();
    int get_op2();
};

class addition: public operation {
  public:
    addition(int, int);
    int exec();
};

class multiplication: public operation {
  public:
    multiplication(int, int);
    int exec();
};
