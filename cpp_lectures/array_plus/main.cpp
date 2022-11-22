#include "array_plus.h"

int main(int argc, char* argv[]){
	const int dim = 12;
	int buf[dim] = {5, 4, 6, 23, 12, 98, 78, 67, 45, 34, 64, 1};
	ArrayPlus arpl(buf, dim);

	arpl.print();

	return 0;
}
