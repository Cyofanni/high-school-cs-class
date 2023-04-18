/* expression in infix notation
     2 + 5 * 3
*/
expr = '2 5 3 * +';
stack = [];

for (i = 0; i < expr.length; i++) {
    if (expr[i] != ' ' && isFinite(expr[i])) {
        stack.push(Number(expr[i]));
    }
    else if (expr[i] == '+' || expr[i] == '*'){
        console.log(stack);
        var ans;
        if (expr[i] == '+') {
	    ans = 0;
	}
	else if (expr[i] == '*') {
	    ans = 1;
	}
        for (j = 1 ; j <= 2; j++) {
	    if (expr[i] == '+') {
		ans += Number(stack.pop());
	    }
	    else if (expr[i] == '*') {
		ans *= Number(stack.pop());
	    }
	}
	stack.push(ans);
    }
}

console.log('Ans:', stack[0]);
