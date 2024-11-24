#include "tictactoe.h"
using namespace std;

int main() {
  tictactoe t1('O');

  while (true) {
    t1.draw();
    int move_row, move_col;
    cout << "\nhello " << t1.get_player_mark() << endl;
    cout << "enter move's row: ";
    cin >> move_row;
    cout << "enter move's column: ";
    cin >> move_col;

    bool w = t1.make_move_check_win(move_row, move_col);
    if (w) {
      t1.draw();
      cout << "\nthe winner is: " << t1.get_player_mark() << endl;
      cout << "exiting game..." << endl;
      break;
    }
  }
}
