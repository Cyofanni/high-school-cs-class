#include <iostream>
using namespace std;

void display_hanoi_tower_moves(int num_disks, int peg_init, int peg_obj, int peg_temp) {
  if (num_disks) {
    display_hanoi_tower_moves(num_disks - 1, peg_init, peg_temp, peg_obj);
    cout << peg_init << ' ' << ' ' << peg_obj << endl;
    display_hanoi_tower_moves(num_disks - 1, peg_temp, peg_obj, peg_init);
  }
}

int main() {
  display_hanoi_tower_moves(4, 1, 3, 2);
}
