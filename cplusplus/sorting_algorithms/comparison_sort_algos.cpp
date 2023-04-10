#include <iostream>
#include <climits>

using namespace std;

void print_array_slice(int a[], int p, int r, int starred_it_ind,
		       int slice_low, int slice_high) {
  for (int i = p; i <= r; i++) {
    if (i == slice_low) {
      cout << "[";
    }
    cout << a[i];
    if (i == starred_it_ind) {
      cout << '*';
    }
    if (i == slice_high) {
      cout<< "]";
    }
    cout << "     ";
  }
  cout << '\n';
}

/*p: lowest slice index, q: middle slice index
  r: highest slice index
 */
void merge(int a[], int p, int q, int r) {
  //allocate left and right arrays on the heap
  //a[p..q] has size q - p + 1, the other +1 makes room for INT_MAX
  int sz_left = q - p + 1 + 1;
  /*a[q + 1..r] has size r - (q+1) + 1 = r - q
    the other +1 makes room for INT_MAX*/
  int sz_right = r - q + 1;
  int *left = new int[sz_left];
  int *right = new int[sz_right];
  /*
  could have used variable-length arrays
  int left[sz_left];
  int right[sz_right];
  */

  int i, j;
  //place first half of a in left
  for (i = 0; i <= sz_left - 2; i++) {
    left[i] = a[p + i];
  }
  /*put sentinel value at last position
    used when left's values have all been placed in a,
    but right has still elements
  */
  left[i] = INT_MAX;

  //place second half of a in right
  for (j = 0; j <= sz_right - 2; j++) {
    right[j] = a[q + 1 + j];
  }
  /*put sentinel value at last position
    used when right's values have all been placed in a,
    but left has still elements
  */
  right[j] = INT_MAX;

  /* left_index: index of the last unchecked left's item
                 starts from 0, because the first item to check
                 in left array is at position 0
     right_index: index of the last unchecked right's item
                  starts from 0, because the first item to check
                  in right array is at position 0
  */
  int left_index = 0, right_index = 0;
  //loop over the slice of a, which begins at p and ends at r
  for (int a_index = p; a_index <= r; a_index++) {
    if (left[left_index] <= right[right_index]) {
      a[a_index] = left[left_index];
      /*left's element at left_index has been placed in the correct
        position of a, the next left item to check will be at left_index + 1
      */
      left_index++;
    }
    else {
      a[a_index] = right[right_index];
      /*right's element at right_index has been placed in the correct
        position of a, the next right item to check will be at right_index + 1
      */
      right_index++;
    }
  }

  delete[] left;
  delete[] right;
}

void merge_sort(int a[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

void exchange_values(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}

/* p: lowest slice index
   r: highest slice index
  */
int partition(int a[], int p, int r) {
  int pivot = a[r]; //take slice's last element as pivot
  int i = p - 1; /*index of the last item put in the lower part;
                   so far, nothing has been put in the lower part,
                   so the index is "before the beginning of the slice"
		  */
  //iterate over the slice, up to 1 item before the pivot
  for (int j = p; j <= r - 1; j++) {
    //let the lower part increase from left to right
    //if a[j] is > pivot, do nothing
    if (a[j] <= pivot) {
      /*put a[j] in the lower part,
        because it is less than or equal to the pivot;
        currently, i is the index of the last item put in the lower part:
         since we're going to put another item in the lower part, increase i
         we're sure that current a[i + 1] is an element of the higher part, because
         i is the last index of the lower part
      */
      i++;
      exchange_values(a[i], a[j]);
    }
  }
  exchange_values(a[i + 1], a[r]);

  return i + 1;
}

void quick_sort(int a[], int p, int r, int a_length) {
  if (p < r) {
    int q = partition(a, p, r);

    quick_sort(a, p, q - 1, a_length);
    quick_sort(a, q + 1, r, a_length);
    //no combine step required, the subarrays are sorted in place
  }
}

int main() {
  int arr[] = {9, 8, 1, 0, 4, 6, 2, 7, 10, 12};
  quick_sort(arr, 0, 9, 10);

  int arr1[] = {9, 8, 1, 0, 4, 6, 2, 7, 10, 12};
  merge_sort(arr, 0, 9);
}
