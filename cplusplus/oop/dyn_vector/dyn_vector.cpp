#include <iostream>
using namespace std;

class dyn_vector {
private:
  int* ptr;
  int size;
public:
  dyn_vector(int size, int val) {
    this -> size = size;
    this -> ptr = new int[size];
    for (int i = 0; i < size; i++) {
      this -> ptr[i] = val;
    }
  }

  dyn_vector(const dyn_vector& v) {
    this -> size = v.size;
    this -> ptr = new int[size];
    for (int i = 0; i < size; i++) {
      this -> ptr[i] = v[i];
    }
  }

  int get_size() {
    return size;
  }

  int& operator[](int i) const {
    return this -> ptr[i];
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      cout << this -> ptr[i] << ' ';
    }
    cout << endl;
  }
  ~dyn_vector() {
    delete[] ptr;
  }

  void insertion_sort() {
    for (int i = 1; i < this -> size; i++) {
      int item = ptr[i];
      int j = i - 1;
      while (j >= 0 && item < ptr[j]) {
        ptr[j + 1] = ptr[j];
        j--;
      }
      ptr[j + 1] = item;
    }
  }

  void swap_2_items(int i, int j) {
    if (i >= 0 && i < size && j >= 0 && j < size) {
      int t = ptr[i];
      ptr[i] = ptr[j];
      ptr[j] = t;
    }
  }

  int partition(int p, int r) {
    int i = p - 1;
    int pivot = ptr[r];
    for (int j = p; j <= r; j++) {
      if (ptr[j] <= pivot) {
        i++;
        swap_2_items(i, j);
      }
    }

    return i;
  }

  void quicksort(int p, int r) {
    if (p < r) {
      int q = partition(p, r);
      quicksort(p, q - 1);
      quicksort(q + 1, r);
    }
  }
};

int main() {
  cout << "vector #1" << endl;
  dyn_vector dv1(12, 0);
  dyn_vector dv2(dv1);
  dv1.print();
  dv1[0] = 8;
  dv1[1] = 7;
  dv1[2] = 10;
  dv1[3] = 15;
  dv1[4] = 80;
  dv1[5] = 1;
  dv1[6] = 80;
  dv1[7] = -1;
  dv1[8] = 58;
  dv1[9] = 40;
  dv1[10] = 38;
  dv1[11] = 6;
  dv1.insertion_sort();
  dv1.print();
  cout << endl << endl;

  cout << "vector #2" << endl;
  dv2[0] = 8;
  dv2[1] = 7;
  dv2[2] = 10;
  dv2[3] = 15;
  dv2[4] = 80;
  dv2[5] = 1;
  dv2[6] = 80;
  dv2[7] = -1;
  dv2[8] = 58;
  dv2[9] = 40;
  dv2[10] = 38;
  dv2[11] = 6;
  dv2.print();
  dv2.quicksort(0, dv2.get_size() - 1);
  dv2.print();
  cout << endl << endl;
}
