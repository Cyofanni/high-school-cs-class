#include <iostream>
#include "matrices.h"
using namespace std;

int main() {
  double m1[4][6] = {{4.5, 3.2, 7, 9, 1, 2.2},
		     {4.8, 3.2, 7, 61, 6, 2.2},
		     {4.5, 3.2, 9, 16, 3, 2.1},
		     {3.5, 3.2, 0.2, 61, 3, 2.0}
                    };

  double m2[6][5] = {{4.5, 6.2, 7, 9, 1},
		     {0.8, 2.2, 7, 61, 6},
		     {1.5, 3.2, 9, 16, 3},
		     {1.5, 4.2, 0.2, 6, 6},
		     {3.5, 13.2, 0.2, 51, 3},
		     {3.3, 3.2, 0.2, 2.1, 2}
                    };

  double m3[4][5];

  matrix_mult(m1, m2, m3);
  print_matrix(*m3, 4, 6);
  cout << endl;

  double system_0[3][4] = {{2, 1, -1, 8},
			   {-3, -1, 2, -11},
			   {-2, 1, 2, -3},
	                  };
  gaussian_elimination(system_0);
  print_matrix(*system_0, 3, 4);
  cout << endl;

  double system_1[3][4] = {{6, 4, -1, 12},
			   {-3, -1, 2, -11},
			   {-2, 1, 2, 8},
	                  };
  cout << endl;
  gaussian_elimination(system_1);
  print_matrix(*system_1, 3, 4);
  /*
  6 4 -1 12
  0 1 1.5 -5
  0 0 -1.83333 23.6667
  */
  cout << endl;
}
