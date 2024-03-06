function verify_parenth_balancing(expr) {
    let stack = [];
    for (let i = 0; i < expr.length; i++) {
        if (expr[i] == '(') {
            stack.push('(');
        }
        else if (expr[i] == ')') {
            if (stack.length == 0) {
                 return false;
            }
            else {
                stack.pop();
            }
        }
    }

    return stack.length == 0;
}

expr = '(e^sin(x)) * 2 (';

if (verify_parenth_balancing(expr)) {
    console.log(expr, "is balanced");
}
else {
    console.log(expr, "is unbalanced");
}
