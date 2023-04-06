#include <iostream>

using namespace std;

void print_array(int *a, int l) {
  for (int i = 0; i < l; i++) {
    cout << a[i] << '\t';
  }
  cout << '\n';
}

int *counting_sort(int input_array[], int len_input_array, int k) {
  /*a contains integers in the interval [0-k]
    initialize the following array so that:
      num_el_lesseq_index[0]: the number of elements == 0
      num_el_lesseq_index[1]: the number of elements == 1
      num_el_lesseq_index[2]: the number of elements == 2
      num_el_lesseq_index[i]: the number of elements == i
    */
  int num_el_lesseq_index[k + 1] = {};

  /*loop over input_array, save the number of elements equal
    to input_array[i] in num_el_lesseq_index[input_array[i]]
   */
  for (int i = 0; i < len_input_array; i++) {
    num_el_lesseq_index[input_array[i]] += 1;
  }

  /*
     if in a list of elements there are:
          x elements that are <= c
          y elements that are == c + 1
     then there are x + y elements thare <= c + 1
     example:
          2 elements in the list are <= 4
          4 elements in the list are == 5
     then 4 + 2 elements in the list are <= 5
     use this idea to populate num_el_lesseq_index with the info:
          num_el_lesseq_index[i]: number of elements less than or equal i
  */
  for (int i = 1; i <= k; i++) {
    num_el_lesseq_index[i] = num_el_lesseq_index[i] + num_el_lesseq_index[i - 1];
  }

  int *output_array = new int[len_input_array];

  /*loop over input_array starting from the end:
     we have an info about input_array[j], i.e. the number of elements
     less or equal than input_array[j], stored in num_el_lesseq_index[input_array[j]];
     in a sorted array, if there are n elements <= x, than x
     must be in position n - 1 (with 0-indexing); n decreases for each duplicate of x;
     example:
        4, 6, 7, 9, 12
        there are 3 elements <= 7, 7 is at index 2 (3 - 1)
        4, 6, 7, 9, 9, 15
        there are 5 elements <= 9, the first (from the end) 9 is at index 4 (5 - 1)
        there's another 9, at index 4 - 1 = 3
   */
  for (int j = len_input_array - 1; j >= 0; j--) {
    output_array[num_el_lesseq_index[input_array[j]] - 1] = input_array[j];
    num_el_lesseq_index[input_array[j]]--;
  }

  return output_array;
}

int main() {
  int ar[1001];
  for (int i = 1000; i >= 0; i--) {
    ar[i] = i;
  }

  int *result = counting_sort(ar, 1001, 1000);
  print_array(result, 1001);

  delete[] result;
}

