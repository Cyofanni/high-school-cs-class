#include <iostream>
using namespace std;

//dangling pointer?: NO
int* f(int* p) {
    return p;
}

//dangling pointer?: YES
double *g() {
    double a;
    return &a;
}

//dangling pointer?: YES
int** h(int* p) {
    return &p;
}

int *sum_arrays_10_wrong(int *arr1, int *arr2) {
    int result[10];
    for (int i = 0; i < 10; i++) {
        result[i] = arr1[i] + arr2[i];
    }

    return result;
}

int main() {
    int x = 5;
    cout << &x << endl;
    cout << f(&x) << endl << endl;

    cout << g() << endl;
    cout << h(&x) << endl;

    //wrong, wrong, wrong code
    int a1[10] = {1, 2, 3, 6, 5, 4, 8, 7, 6, 1};
    int a2[10] = {1, 2, 3, 6, 5, 4, 8, 7, 6, 1};
    int *res = sum_arrays_10_wrong(a1, a2);
    for (int i = 0; i < 10; i++) {
        cout << res[i] << '\t';
    }
    cout << '\n';
}
