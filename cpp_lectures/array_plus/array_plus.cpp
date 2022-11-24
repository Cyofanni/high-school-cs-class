#include <iostream>
#include "array_plus.h"

ArrayPlus::ArrayPlus(int* v, int size){
	this->v = v;
	this->size = size;
}

void ArrayPlus::print(){
	int i = 0;
	while (i < size){
		std::cout << *(this->v + i) << '\t';
		++i;	
	}
	std::cout << '\n';
}

