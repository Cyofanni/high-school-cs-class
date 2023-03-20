#include <iostream>

using namespace std;

int inc_1(int n) {
    return n + 1;
}

int main() {
    //declare and initialize int_1_ptr as pointer to inc_1
    int (*inc_1_ptr ) (int) = &inc_1;
    //call inc_1 directly
    cout << inc_1(5) << endl;
    //call inc_1 through pointer
    cout << (*inc_1_ptr)(5) << endl;
}
