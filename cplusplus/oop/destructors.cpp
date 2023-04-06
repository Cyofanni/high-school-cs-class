#include <iostream>

class B{
private:
    int x;
    int y;
public:
    B(){
        std::cout << "creating object of class B" << std::endl;
    }
    ~B(){
        std::cout << "destroying object of class B" << std::endl;
    }
};

class C{
private:
    int x;
    int y;

public:
    C(){
       std::cout << "creating object of class C" << std::endl;
    }
    ~C(){
       std::cout << "destroying object of class C" << std::endl;
    }
};

class D{
private:
    int d;
public:
    D(){
        std::cout << "creating object of class D" << std::endl;
    }
    ~D(){
        std::cout << "destroying object of class D" << std::endl;
    }
};

class E{
private:
    int d;
public:
    E(){
        std::cout << "creating object of class E" << std::endl;
    }
    ~E(){
        std::cout << "destroying object of class E" << std::endl;
    }
};

void stack_allocation_deallocation(){
    B b;
    C c;
    D d;
    E e;
    std::cout << "address of b " << &b << std::endl;
    std::cout << "address of c " << &c << std::endl;
    std::cout << "address of d " << &d << std::endl;
    std::cout << "address of e " << &e << std::endl;
}

int main(int argc, char* argv[]){
    stack_allocation_deallocation();

    return 0;
}
