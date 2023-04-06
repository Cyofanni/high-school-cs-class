#include <iostream>
using namespace std;

union var_var {
	unsigned int ui;
	int i;
	long int li;
};

int main() {
	union var_var v;
	v.li = 0xCAFEDEADBEBEBABA;
	cout << v.ui << endl;
	cout << v.i << endl;
	cout << v.li << endl;
}
