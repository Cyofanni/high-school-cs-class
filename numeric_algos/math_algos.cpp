long long int factorial_head_recursive(int n){
	if (n >= 0){
		if (n == 0){
			return 1;
		}
		int result_of_rec_call = factorial_head_recursive(n - 1);
		return n * result_of_rec_call;
	}
	else {
		return -1;
	}
}

long long int factorial_tail_recursive(int n, long long int result_accumulator){
	if (n >= 0){
		if (n == 0){
			return result_accumulator;
		}
		
		result_accumulator = n * result_accumulator;
		return factorial_tail_recursive(n - 1, result_accumulator);
	}
	else{
		return -1;
	}
}

long long int factorial_iterative(int n){
	if (n >= 0){
		long long int result = 1;
		int i = n;
		int result_accumulator = 1;
		
		while (i > 1){
			result_accumulator *= i;
			i--;
		}
		
		return result_accumulator;
	}
	else{
		return -1;
	}
}
