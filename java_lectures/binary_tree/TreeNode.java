class TreeNode{
    int key;
    TreeNode leftChild;
    TreeNode rightChild;

    TreeNode(int key, TreeNode leftChild, TreeNode rightChild){
        this.key = key;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }


    void preOrderWalkAndPrint(){
        if (this != null){
            System.out.print(this.key);
            System.out.print("(");
            if (this.leftChild != null){
                this.leftChild.preOrderWalkAndPrint();
            }
            else{
                System.out.print("nil");
            }

            System.out.print(", ");
            if (this.rightChild != null){
                this.rightChild.preOrderWalkAndPrint();
            }
            else{
                System.out.print("nil");
            }
            System.out.print(")");
        }
    }

    int getHeight(){
        if (this == null){
            return 0;
        }
        if (this.leftChild == null && this.rightChild == null){
            return 0;
        }
        int heightLeftSubTree = 0;
        int heightRightSubTree = 0;
        if (this.leftChild != null){
            heightLeftSubTree = this.leftChild.getHeight();
        }
        if (this.rightChild != null){
            heightRightSubTree = this.rightChild.getHeight();
        }

        if (heightLeftSubTree >= heightRightSubTree){
            return heightLeftSubTree + 1;
        }
        return heightRightSubTree + 1;
    }
}

/*height(T) = max(height(T.left),height(T.right))+1 =
  max(max(height(T.left.left),height(T.left.right))+1,max(height(T.right.left),height(T.right.right))+1)+1 =
  max(max(0,0)+1,max(height(T.right.left),0)+1)+1 =
  max(max(0,0)+1,max(max(height(T.right.left.left),height(T.right.left.right))+1,0)+1)+1 =
  max(max(0,0)+1,max(max(0,0)+1,0)+1)+1 =
  max(0+1,max(0+1,0)+1)+1 =
  max(1,max(1,0)+1)+1 =
  max(1,1+1)+1 =
  max(1,2)+1 =
  2+1 =
  3
*/


/*
   height(T): returns int
       if (t is nil):
            return 0
       if t.left is nil and r.right is nil:
            return 0
       int heightLeftSubTree = height(T.left)
       int heightRightSubTree = height(T.right)

       return max(heightLeftSubTree, rightSubTree) + 1

*/
