#include "basic_array_algorithms.h"
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;

int main(){
    srand(time(NULL));
    const int size = 20;
    int array[size];
    int array_copy[size];

    for (int i = 0; i < size; i++){
        array[i] = rand() % 150;
        array_copy[i] = array[i];
    }

    print_iterative(array, size);
    selection_sort(array, size);
    print_iterative(array, size);

    auto t0 = chrono::high_resolution_clock::now();
    insertion_sort(array, size);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Insertion sort:  " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanoseconds passed\n";

    auto t2 = chrono::high_resolution_clock::now();
    bubble_sort(array_copy, size);
    auto t3 = chrono::high_resolution_clock::now();
    cout << "Bubble sort:    " << chrono::duration_cast<chrono::nanoseconds>(t3 - t2).count() << " nanoseconds passed\n";
}
