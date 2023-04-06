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


void print_array_insertion_sort_debug(int* v, int size, int sorted_until){
    int i = 0;
    while (i < size){
        if (i <= sorted_until){
            cout << '*' << v[i] << '\t';
        }
        else {
            cout << v[i] << '\t';
        }
        i++;
    }

    cout << endl;
}


//insertion sort
void insertion_sort(int v[], int size){
    //print_array_insertion_sort_debug(v, size, 0);

    for (int i = 1; i < size; i++){
        int item = v[i];
        int j = i - 1;
        while (j >= 0 && item < v[j]){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = item;

        //print_array_insertion_sort_debug(v, size, i);
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
    bool is_sorted = false;

    while (!is_sorted){
        //print_array_bubble_sort_debug(v, size);
        is_sorted = true;  //suppose there won't be any swap, i.e. has been sorted
        for (int i = 0; i <= size - 2; i++){
            if (v[i] > v[i + 1]){
                int t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
                is_sorted = false;
            }
        }
    }
}

//bubble sort
/*
  [5, 8, 45, 35, 1]
  Result of first scan, inner loop until index 3:
    [5, 8, 35, 1, 45*]
  Result of second scan, inner loop until index 2:
    [5, 8, 1, 35*, 45*]
  Result of third scan, inner loop until index 1:
    [5, 1, 8*, 35*, 45*]
  Result of fourth scan, inner loop until index 0:
    [1, 5*, 8*, 35*, 45*]
*/
void bubble_sort(int* v, int size){
    bool is_sorted = false;

    for (int i = size - 1; i > 0 && !is_sorted; i--){
        is_sorted = true;
        for (int j = 0; j < i; j++){
            if (v[j] > v[j + 1]){
                //swap
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                is_sorted = false;
            }
        }
    }
}

//selection sort
void selection_sort(int* v, int size){
    for (int i = 0; i <= size - 1; i++){
        int curr_smallest_item = v[i];
        int curr_smallest_item_index = i;
        for (int j = i + 1; j <= size - 1; j++){
            if (v[j] < curr_smallest_item){
                curr_smallest_item = v[j];
                curr_smallest_item_index = j;
            }
        }
        int t = v[i];
        v[i] = curr_smallest_item;
        v[curr_smallest_item_index] = t;
    }
}
