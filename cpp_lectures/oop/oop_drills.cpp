#include <iostream>
using namespace std;

class A{
private:
	char c;
	int i;
	double d;
public:
	A(){
		cout << "called default constructor" << endl; 
	}
	A(char c){
		(*this).c = c;
		cout << "called 1-argument constructor" << endl;
	}
	A(char c, int i){
		(*this).c = c;
		(*this).i = i;
		cout << "called 2-argument constructor" << endl;
	}
	A(char c, int i, double d){
		(*this).c = c;
		(*this).i = i;
		(*this).d = d;
		cout << "called 3-argument constructor" << endl;
	}
	
	char get_c() const{
		return c;
	}
	int get_i() const{
		return i;
	}
	double get_d() const{
		return d;
	}
};

void print(const A& a){
	cout << '[' << a.get_c() << ", " << a.get_i() << ", " << a.get_d() << ']' << endl;
}

int main(int argc, char* argv[]){	
	A a('a', 78, 3.422);
	print(a);
	print({'b', 87, 43.34});
	
	
	if (argc > 1){
		if (strncmp(argv[1], "0", 1) == 0){
			A a1;
		}
		else if (strncmp(argv[1], "1", 1) == 0){
			A a2('a');
		}
		else if (strncmp(argv[1], "2", 1) == 0){
			A a3('a', 2);
		}
		else if (strncmp(argv[1], "3", 1) == 0){
			A a4('a', 2, 3.67);
		}
	}
	else {
		cout << "command line argument not provided";
	}
}