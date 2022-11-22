#include <iostream>
#include <cmath>

using namespace std;

#define N_ITERATIONS 20

long double f(long double x){
	return pow(x, 3) + 4*x - 2;
}

long double f1(long double x){
	return pow(x, 3) + 2*pow(x, 2) + 10*x - 20;
}

long double f2(long double x){
	return pow(x, 2) - x - 1;
}

long double f3(long double x){
	return x - 1;
}

long double f4(long double x){
	return pow(x, 2) - 16;
}

int main(){
	long double left_x = 1.0f;
	long double right_x = 2.0f;
	long double middle_x;

	long double left_value, right_value, middle_value;
	
	int i = 0;
	while (i < N_ITERATIONS){
		middle_x = (left_x + right_x) / 2;
	        left_value = f2(left_x);
		right_value = f2(right_x);
		middle_value = f2(middle_x);
		
		if (middle_value * right_value < 0){
			left_x = middle_x;
		}
		else if (left_value * middle_value < 0){
			right_x = middle_x;
		}

		i++;
	}


	printf("approximated solution in %d steps is: %.15Lf\n", i, middle_x);
	return 0;
}
