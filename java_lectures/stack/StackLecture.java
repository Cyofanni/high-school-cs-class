class StackLecture{
    static boolean checkParenthesisBalance(String expr){
        boolean balanced = false;

        StackChar st = new StackChar(expr.length() * 3);

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
        StackChar[] si = new StackChar[30];
        si[0] = new StackChar(20);
        si[1] = new StackChar(10);
        System.out.println(si[0]);
        System.out.println(si[0]);

        int j;
        for (j = 0; j < 10; j++){
            System.out.println("i: " + j);
        }

        StackIntNode st = new StackIntNode(0, null, null, true);

        int i = 0;
        while (i < 10){
            st = st.push(i);
            i++;
        }

        while (st.isEmpty() == false){
            st.print();
            st = st.pop();
        }


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
