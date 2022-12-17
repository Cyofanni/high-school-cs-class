class TreeNode{
    int key;
    TreeNode leftChild;
    TreeNode rightChild;
    boolean visitedLeft = false;
    boolean visitedRight = false;

    TreeNode(int key, TreeNode leftChild, TreeNode rightChild){
        this.key = key;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }

    void preOrderWalkAndPrint(){
        if (this == null){
            System.out.print("nil");
            return;
        }
        System.out.print(this.key);
        System.out.print("(");
        if (this.leftChild != null){
            this.leftChild.preOrderWalkAndPrint();
        }
        System.out.print(",");
        if (this.rightChild != null){
            this.rightChild.preOrderWalkAndPrint();
        }
        System.out.print(")");
    }

    int getHeight(){
        if(this == null){
            return 0;
        }
        if(this.leftChild == null && this.rightChild == null){
            return 0;
        }
        int heightLeft = 0;
        int heightRight = 0;
        if(this.leftChild != null){
            heightLeft = this.leftChild.getHeight();
        }
        if(this.rightChild != null){
            heightRight = this.rightChild.getHeight();
        }
        if(heightLeft >= heightRight){
            return heightLeft + 1;
        }
        return heightRight + 1;
    }

    int getHeightIterative(){
        int path_length_counter = 0;
        int height = 0;
        StackTreeNode st = new StackTreeNode(10);
        st.push(this);

        while (st.isEmpty() == false){
            TreeNode currentNode = st.peek();

            //if left subtree of current node has not yet been visited, visit it
            if (currentNode.visitedLeft == false){
                currentNode.visitedLeft = true;
                if (currentNode.leftChild != null){
                    currentNode = currentNode.leftChild;
                    st.push(currentNode);
                    path_length_counter++;
                }
            }
            //if left subtree of currentnode has already been visited, visit its right child
            else if (currentNode.visitedRight == false){
                currentNode.visitedRight = true;
                if (currentNode.rightChild != null){
                    currentNode = currentNode.rightChild;
                    st.push(currentNode);
                    path_length_counter++;
                }
            }
            else {
                st.pop();
                if (path_length_counter >= height){
                    height = path_length_counter;
                }
                path_length_counter--;
            }


        }

        return height;
    }
}

class StackTreeNode{
    TreeNode[] stack_array;
    int top;
    int size;

    StackTreeNode(int size){
        this.stack_array = new TreeNode[size];
        this.top = -1;
        this.size = size;
    }

    int push(TreeNode item){
        if (top < size-1){
            top++;
            stack_array[top] = item;
        }

        return top;
    }

    int pop(){
        if (top >= 0){
            top--;
        }

        return top;
    }

    boolean isEmpty(){
        return top == -1;
    }

    boolean isFull(){
        return top == size - 1;
    }

    TreeNode peek(){
        return stack_array[top];
    }
}
