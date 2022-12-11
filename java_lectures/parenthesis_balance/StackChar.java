class StackChar{
    private char[] stack_array;
    private int top;
    private int size;

    public StackChar(int size){
        this.stack_array = new char[size];
        this.top = -1;
        this.size = size;
    }

    public int push(char item){
        if (top < size-1){
            top++;
            stack_array[top] = item;
        }

        return top;
    }

    public int pop(){
        if (top >= 0){
            top--;
        }

        return top;
    }

    public char peek() throws StackPeekException{
        if (top >= 0){
            return stack_array[top];
        }
        else {
            throw new StackPeekException();
        }
    }

    public void printStack(){
        for (int i = top; i >= 0; i--){
            System.out.println("  [ " + stack_array[i] + " ]");
            if (i > 0){
                System.out.println("  ----------");
            }
        }
    }

    public boolean is_empty(){
        return top == -1;
    }

    public boolean is_full(){
        return top == size - 1;
    }
}