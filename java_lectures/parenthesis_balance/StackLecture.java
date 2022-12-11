class StackLecture{
    static boolean checkParenthesisBalance(String expr){
        boolean balanced = false;

        StackChar st = new StackChar(expr.length());

        boolean moreClosed = false; //becomes true when current character is ')' and the stack is already empty
        for (int i = 0; i < expr.length() && moreClosed == false; i++){
            if (expr.charAt(i) == '('){
                int sp = st.push('(');
            }
            else {
                if (expr.charAt(i) == ')'){
                    if (st.is_empty() == false){
                        int sp = st.pop();
                    }
                    else{
                        moreClosed = true;
                    }
                }
            }

        }

        if (st.is_empty() && moreClosed == false){
            balanced = true;
        }

        return balanced;
    }

    public static void main(String[] args){
        StackIntNode st = new StackIntNode(0, null, null, true);

        String expr0 = "e(i*pi) + 1 = 0";
        String expr1 = "()))((";
        String expr2 = "()()))()";
        String expr3 = "()(()(()))";
        String expr4 = "(a * (b + 2^(x + k))";

        if (checkParenthesisBalance(expr0)){
            System.out.println(expr0 + " is parenthetically correct");
        }
        else {
            System.out.println(expr0 + " is not parenthetically correct");
        }
    }
}