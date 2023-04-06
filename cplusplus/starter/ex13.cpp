#include <iostream>
#include <climits>
using namespace std;

/*

************
*          *
* ******** *
* *      * *
* *      * *
* *      * *
* *      * *
* *      * *
* *      * *
* ******** *
*          *
************

*/

int main() {
  for (int i = 1; i <= 12; i++) {
    if (i == 1 || i == 12) {
      cout << "************" << endl;
    }
    else if (i == 3 || i == 10) {
      cout << "* ******** *" << endl;
    }
    else if (i > 3 && i < 10) {
      cout << "* *      * *" << endl;
    }
    else {
      cout << "*          *" << endl;
    }
  }
}
