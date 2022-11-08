#include "basic_array_algorithms.h"

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


//insertion sort
void insertion_sort(int* v, int size){
	for (int i = 0; i < size; i++){
		int item = v[i];
		int j = i - 1;
		while (j >= 0 && item < v[j]){
			//cout << "inner iteration" << endl;
			v[j] = v[j - 1];
			j--;
		}
		v[j + 1] = item;
	}
}

//bubble sort
void bubble_sort(int* v, int size){
	for (int i = size - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			//cout << "inner iteration" << endl;
			if (v[j] > v[j + 1]){
				//swap
				int t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
			}
		}
	}
}