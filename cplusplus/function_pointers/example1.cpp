#include <iostream>

using namespace std;

int inc_1(int n) {
	return n + 1;
}

int inc_2(int n) {
	return n + 2;
}

int inc_3(int n) {
	return n + 3;
}

int inc_4(int n) {
	return n + 4;
}

int main() {
	//declare an array of function pointers
	int (*fptr_array[4]) (int);
	fptr_array[0] = &inc_1;
	fptr_array[1] = &inc_2;
	fptr_array[2] = &inc_3;
	fptr_array[3] = &inc_4;
	for (int i = 0; i < 4; i++) {
		cout << (*fptr_array[i])(0) << endl;
	}
}
