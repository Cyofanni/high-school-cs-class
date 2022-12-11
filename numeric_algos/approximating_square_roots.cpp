#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main (int argc, char* argv[]) {
    long double number;
    do {
        cout << "enter a positive real number to approximate its square root, a negative one to exit program: ";
        cin >> number;
        long double precision;
        cout << "enter a precision value (from 1.0e0L up to 1.0e-15L): ";
        cin >> precision;
        if (number >= 0 && (precision == 1.0e0L || precision == 1.0e-1L || precision == 1.0e-2L || precision == 1.0e-3L
            || precision == 1.0e-4L || precision == 1.0e-5L || precision == 1.0e-6L || precision == 1.0e-7L
            || precision == 1.0e-8L || precision == 1.0e-9L || precision == 1.0e-10L || precision == 1.0e-11L
            || precision == 1.0e-12L || precision == 1.0e-13L || precision == 1.0e-14L || precision == 1.0e-15L)) {
            long double step = 1.0L;
            long double approximation = 0.0L;

            while (step >= precision) {
                while (approximation*approximation <= number) {
                    approximation = approximation + step;
                }
                approximation = approximation - step;

                step = step / 10.0;    //new step is 1/10 of the current one
            }

            printf ("approximation of square root according to C++ math library is (up to 10^-15) %.15f\n", sqrt(number));
            if (precision == 1.0e0L) {
                printf ("approximation of square root up to requested precision is %.f\n\n", approximation);
            }
            else if (precision == 1.0e-1L) {
                printf ("approximation of square root up to requested precision is %.1f\n\n", approximation);
            }
            else if (precision == 1.0e-2L) {
                printf ("approximation of square root up to requested precision is %.2f\n\n", approximation);
            }
            else if (precision == 1.0e-3L) {
                printf ("approximation of square root up to requested precision is %.3f\n\n", approximation);
            }
            else if (precision == 1.0e-4L) {
                printf ("approximation of square root up to requested precision is %.4f\n\n", approximation);
            }
            else if (precision == 1.0e-5L) {
                printf ("approximation of square root up to requested precision is %.5f\n\n", approximation);
            }
            else if (precision == 1.0e-6L) {
                printf ("approximation of square root up to requested precision is %.6f\n\n", approximation);
            }
            else if (precision == 1.0e-7L) {
                printf ("approximation of square root up to requested precision is %.7f\n\n", approximation);
            }
            else if (precision == 1.0e-8L) {
                printf ("approximation of square root up to requested precision is %.8f\n\n", approximation);
            }
            else if (precision == 1.0e-9L) {
                printf ("approximation of square root up to requested precision is %.9f\n\n", approximation);
            }
            else if (precision == 1.0e-10L) {
                printf ("approximation of square root up to requested precision is %.10f\n\n", approximation);
            }
            else if (precision == 1.0e-11L) {
                printf ("approximation of square root up to requested precision is %.11f\n\n", approximation);
            }
            else if (precision == 1.0e-12L) {
                printf ("approximation of square root up to requested precision is %.12f\n\n", approximation);
            }
            else if (precision == 1.0e-13L) {
                printf ("approximation of square root up to requested precision is %.13f\n\n", approximation);
            }
            else if (precision == 1.0e-14L) {
                printf ("approximation of square root up to requested precision is %.14f\n\n", approximation);
            }
            else if (precision == 1.0e-15L) {
                printf ("approximation of square root up to requested precision is %.15f\n\n", approximation);
            }
        }
        else {
            cout << "incorrect input" << endl << endl;
        }

    }
    while (number >= 0);

    cout << "entered negative number, exiting program..." << endl;

    return 0;
}
