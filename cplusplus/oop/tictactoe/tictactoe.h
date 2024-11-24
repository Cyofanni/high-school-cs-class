#include <iostream>

class tictactoe {
  private:
    char board[3][3];
    char curr_player_mark;
    void switch_player_mark();
    bool check_win() const;
  public:
    tictactoe(char);
    char get_player_mark() const;
    bool make_move_check_win(int, int);
    void draw() const;
};
