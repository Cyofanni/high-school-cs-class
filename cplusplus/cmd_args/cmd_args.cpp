#include <iostream>
using namespace std;

//run this way: ./cmd_argc banana cherry strawberry

int main(int argc, char* argv[]) {
  cout << "number of command-line arguments: " << argc << endl << endl;
  cout << "list of command-line arguments:" << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
}
