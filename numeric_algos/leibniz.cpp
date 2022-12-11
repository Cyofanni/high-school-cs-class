#include <iostream>
using namespace std;

int main(){
    const long int n_iterations = 10000000000;
    double approx_pi = 4.0;
    long int i = 1;
    int sign = -1;
    double denominator = 3.0;

    while (i <= n_iterations){
        approx_pi = approx_pi + sign * 4.0 / denominator;
        denominator += 2;
        sign = -sign;
        i++;
    }

    printf("%.15f\n", approx_pi);
}
