expr = '()()()()()(((())))';
stack = [];

function verify_parenth_balancing(expr) {
    is_unbalanced = false;
    for (i = 0; i < expr.length && is_unbalanced == false; i++) {
        if (expr[i] == '(') {
            stack.push('(');
        }
        else if (expr[i] == ')') {
            if (stack.length == 0) {
                 is_unbalanced = true;
            }
            else {
                stack.pop();
            }
        }
    }

    return stack.length == 0 && !is_unbalanced;
}

if (verify_parenth_balancing(expr)) {
    console.log(expr, "is balanced");
}
else {
    console.log(expr, "is unbalanced");
}
