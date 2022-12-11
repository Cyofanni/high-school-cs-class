int g(){
	int g_local = 27;
	return g_local;
}

int f(){
	int r = g();
	int f_local = 17;
	return f_local;
}

int main(){
	int r = f();
	int i = 0;
	while (i < 10){
		i++;
	}

	return 0;
}
