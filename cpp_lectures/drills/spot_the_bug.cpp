#include <iostream>

//spot the bug - 1
char* f(){
	char c = 'a';
	return &c;
}

//spot the bug - 2
double* g(){
	double buf[10] = {};
	return buf;
}

//spot the bug - 3
void read_stdin_into_buffer(char* buf, int dim){
	int position;
	char value;
	
	std::cin >> position;
	std::cin >> value;
	
	buf[position] = value;
}

//spot the bug - 4
void print_buffer(char* buf, int dim){
	int k = dim;
	int i = 0;
	while (i <= k){
		std::cout << buf[i];
		i++;
	}
}

//spot the bug - 5
void h(){
	const int sz_src = 20;
	const int sz_dest = 10;
	
	int src[20];
	int dest[10];
	
	int i = 0;
	while (i < sz_src){
		dest[i] = src[i];
		i++;
	}
}

//spot the bug - 6
int r(int n){
	int k = 0;
	if (k == 1){
		return 1;
	}
	return n * r(n - 1);
}

//spot the bug - 7
int binary_search(int* a, int size, int searched_key){
	bool found = false;
	int m;
	int l = 0; 
	int h = size - 1;
	
	while (!found){
		m = (l + h) / 2;
		if (a[m] == searched_key){
			found = true;
		}
		else if (searched_key > a[m]){
			l = m + 1;
		}
		else{
			h = m - 1;
		}
	}
	
	return m;
}


//spot the bug - 8
void func0(int* c, int n){
	if (n % 2 == 0){
		c = nullptr;
	}
	*c;
}


//spot the bug - 9
void l(int n){
	int* b;
	while (true){
		b = new int[n];
	}
}


//spot the bug - 10
void func1(int* p, int dim){
	int k;
	int i;
	for (i = k; i < dim; i++){
		*(p + i) *= p[i];
	}
}

int main(){

	return 0;
}