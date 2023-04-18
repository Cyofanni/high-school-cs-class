/* expression in infix notation
     2 + 5 * 3
*/
expr = '(((4 + 3) * 3) + 9)';
operators_stack = [];
rpn_expr = '';

for (i = 0; i < expr.length; i++) {
    if (expr[i] != ' ' && isFinite(expr[i])) {
        rpn_expr += expr[i] + ' ';
    }
    else if (expr[i] == '+' || expr[i] == '*'){
        operators_stack.push(expr[i]);
    }
    else if (expr[i] == ')') {
        rpn_expr += operators_stack.pop() + ' ';
    }
}

console.log('Expression in infix notation:', expr);
console.log('Expression in Reverse Polish Notation:', rpn_expr);
