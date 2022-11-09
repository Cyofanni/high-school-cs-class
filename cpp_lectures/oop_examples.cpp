#include <iostream>
using namespace std;

class A{
private:
	char c;
	int i;
	double d;
public:
	A(){
		cout << "called default constructor"; 
	}
	A(char c){
		(*this).c = c;
		cout << "called 1-argument constructor";
	}
	A(char c, int i){
		(*this).c = c;
		(*this).i = i;
		cout << "called 2-argument constructor";
	}
	A(char c, int i, double d){
		(*this).c = c;
		(*this).i = i;
		(*this).d = d;
		cout << "called 3-argument constructor";
	}
};

int main(int argc, char* argv[]){
	if (argc > 1){
		if (strncmp(argv[1], "0", 1) == 0){
			A a;
		}
		else if (strncmp(argv[1], "1", 1) == 0){
			A a('a');
		}
		else if (strncmp(argv[1], "2", 1) == 0){
			A a('a', 2);
		}
		else if (strncmp(argv[1], "3", 1) == 0){
			A a('a', 2, 3.67);
		}
	}
	else {
		cout << "command line argument not provided";
	}
}