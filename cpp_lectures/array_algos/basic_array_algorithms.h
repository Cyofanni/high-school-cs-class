#include <iostream>


struct pos_value{
	double value;
	int position;
};

//prints an array using the [] syntax
void print_iterative(int*, int);


//prints an array using pointer arithmetic
void print_iterative_ptr_arithm(int*, int);


//recursively print an array
void print_recursive(int*, int);


void print_array_bubble_sort_debug(int*, int);


/*left shifts a slice of an int array and fill the gap with a value passed
  as a parameter
    eg) left_shift_slice([5, 6*, 8, 2*, 9, 12], from: 1, to: 3, gap_fill: 999, size: 6)
		---> [5, 8, 2, 999, 9, 12]
  Do nothing if slice limits ends go beyond array's size.
*/
void left_shift_slice(int*, int, int, int, int);


/*right shifts a slice of an int array and fills in the gap with a value passed
  as a parameter
    eg) left_shift_slice([5, 6, 8, 2, 9, 12], from: 3, to: 5, gap_fill: 999, size: 6)
		---> [5, 8, 2, 999, 2, 9]
    Do nothing if slice limits ends go beyond array's size.
*/
void right_shift_slice(int*, int, int, int, int);


//compare two int arrays
bool compare(int*, int, int*, int);

//verifies if an array of characters is palindrome
bool is_palindrome(char* s);

//get max value of an array and its position
double max(double*, int);


//get min value of an array and its position
double min(double*, int);


//linear search algorithm
int linear_search(int*, int, int);


//iterative binary ("logarithmic") search
int binary_search_iterative(int*, int, int);


//recursive binary ("logarithmic") search
int binary_search_recursive(int*, int, int);


//verifies if an int array is sorted in ascending or descending order
bool is_sorted(int*, int, bool);


//insertion sort
void insertion_sort(int*, int);


//selection sort
void selection_sort(int*, int);


//naive bubble sort
void bubble_sort_naive(int* v, int size);


//bubble sort
void bubble_sort(int*, int);


//merges two sorted arrays
void merge(int*, int, int*, int);


//merge sort
void merge_sort(int*, int);


//prints upper triangular submatrix of a 5*5 matrix
void print_triu(int[][5]);


//prints upper triangular submatrix of a 5*5
void print_triu(int[][5]);


//verifies symmetry of a 5*5 matrix
bool is_symmetric(int [][5]);

