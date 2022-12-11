#include <iostream>
#include "math_algos.h"
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a;
    cin >> b;

    cout << gcd_euclid_iterative(a, b) << endl;
}
