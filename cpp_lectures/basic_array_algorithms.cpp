#include <iostream>
#include "basic_array_algorithms.h"

using namespace std;

//prints an array using the [] syntax
void print_iterative(int* buf, int size){
	if (buf){
		for (int i = 0; i < size; i++){
			cout << buf[i] << '\t';
		}
		cout << '\n';
	}
}


//prints an array using pointer arithmetic
void print_iterative_ptr_arithm(int* buf, int size){
	if (buf){
		for (int i = 0; i < size; i++){
			cout << *(buf + i) << '\t';
		}
		cout << '\n';
	}
}