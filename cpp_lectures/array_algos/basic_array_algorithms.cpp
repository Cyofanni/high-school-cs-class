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


void print_array_bubble_sort_debug(int* v, int size){
	int i = 0;
	while (i < size){
		if (i < size - 1){
			if (v[i] > v[i + 1]){
				cout << '*' << v[i] << "------*";
			}
			else {
				cout << v[i] << '\t';
			}
		}
		else {
				cout << v[i] << '\t';
		}
	
		i++;
	}
	
	cout << endl;
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


//iterative binary ("logarithmic") search
int binary_search_iterative(int* v, int size, int key){
	int l = 0;
	int h = size - 1;
	int m;
	bool found = false;
	int index_of_key = -1;
	
	while (!found && h >= l){
		m = (l + h) / 2;
		if (key == v[m]){
			index_of_key = m;
			found = true;
		}
		else if (key > v[m]){
			l = m + 1;
		}
		else{
			h = m - 1;
		}
	}
	
	return index_of_key;
}

//naive bubble sort
void bubble_sort_naive(int* v, int size){
	bool swap_happened = false;

	do{
		print_array_bubble_sort_debug(v, size);
		swap_happened = false;  //suppose there won't be any swap, i.e. has been sorted
		for (int i = 0; i <= size - 2; i++){
			if (v[i] > v[i + 1]){
				int t = v[i];
				v[i] = v[i + 1];
				v[i + 1] = t;
				swap_happened = true;
			}
		}
	}
	while (swap_happened);
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