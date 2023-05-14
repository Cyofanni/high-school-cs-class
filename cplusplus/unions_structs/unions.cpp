#include <iostream>
#include <iomanip>
using namespace std;

union var_rec {
	unsigned short usi;
	unsigned int ui;
	unsigned long int uli;
        float d;
};

int main() {
	union var_rec v;
	v.uli = 0xCAFEDEADBEBEBABA;
	cout << v.usi << endl;
	cout << v.ui << endl;
	cout << v.uli << endl;
        cout << setprecision(12) << v.d << endl;
}
