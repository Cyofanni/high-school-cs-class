#include <iostream>
using namespace std;

int get_next_and_kill(int* soldiers, int n_soldiers, int i) {
  int living_soldiers = 0;
  for (int i = 0; i < n_soldiers; i++) {
    if (soldiers[i] != 0) {
      living_soldiers++;
    }
  }
  if (living_soldiers == 1) {
    return -1;
  }

  int pos = -1;
  for (int j = (i + 1) % n_soldiers; j < n_soldiers && pos == -1;
                      j = (j + 1) % n_soldiers) {
    //a soldier cannot kill himself
    if (j != i && soldiers[j] != 0) {
      soldiers[j] = 0;
      pos = j;
    }
  }

  return pos;
}

void print_soldiers(int* soldiers, int n_soldiers) {
  for (int i = 0; i < n_soldiers; i++) {
    cout << soldiers[i] << ' ';
  }
  cout << endl;
}

int josephus(int n) {
  int* soldiers = new int[n];
  for (int i = 0; i < n; i++) {
    soldiers[i] = i + 1;
  }

  int i = 0;
  int next = 0;

  while (next != -1) {
    //only living soldiers can kill
    if (soldiers[i] != 0) {
      next = get_next_and_kill(soldiers, n, i);
      i = (next + 1) % n;
    }
    else {
      i = (i + 1) % n;
    }
  }

  //only one survivor
  for (int i = 0; i < n; i++) {
    if (soldiers[i] != 0) {
      return soldiers[i];
    }
  }

  delete[] soldiers;
  return -1;
}

int main() {
  for (int i = 1; i <= 30; i++) {
    cout << i << " " << josephus(i) << endl;
  }
}
