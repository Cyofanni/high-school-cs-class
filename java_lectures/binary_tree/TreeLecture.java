class TreeLecture{
    public static void main(String[] args){
        TreeNode tree_0 = new TreeNode(5, null, null);
        tree_0.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_0.getHeightIterative());
        System.out.println(tree_0.getHeight());
        System.out.println();

        TreeNode tree_1 = new TreeNode(7, new TreeNode(4, null, null), null);
        tree_1.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_1.getHeightIterative());
        System.out.println(tree_1.getHeight());
        System.out.println();

        TreeNode tree_2 = new TreeNode(12, new TreeNode(15, null, null),
                                       new TreeNode(16, null, null));

        tree_2.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_2.getHeightIterative());
        System.out.println(tree_2.getHeight());
        System.out.println();

        TreeNode tree_3 = new TreeNode(12, new TreeNode(10, null, null),
                                       new TreeNode(17, null, new TreeNode(15,
                                       null, new TreeNode(15, null, null))));
        tree_3.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_3.getHeightIterative());
        System.out.println(tree_3.getHeight());
        System.out.println();

        TreeNode tree_4 = new TreeNode(12, null, new TreeNode(13, null, new TreeNode(14, null,
                                new TreeNode(15, null, new TreeNode(16, null, null)))));
        //12->13->14->15->16

        tree_4.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_4.getHeightIterative());
        System.out.println(tree_4.getHeight());
        System.out.println();


        TreeNode tree_5 = new TreeNode(12, null, new TreeNode(13, null, new TreeNode(14, null,
                                new TreeNode(15, null, new TreeNode(16, new TreeNode(16, null, null), null)))));
        //12->13->14->15->16

        tree_5.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_5.getHeightIterative());
        System.out.println(tree_5.getHeight());
        System.out.println();

        TreeNode tree_6 = new TreeNode(6,new TreeNode(5,new TreeNode(3,new TreeNode(2,new TreeNode(6,null,null),null),null),new TreeNode(6,null,new TreeNode(4,new TreeNode(1,new TreeNode(17,null,null),null),null))),new TreeNode(1,new TreeNode(4,null,null),null));
        tree_6.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_6.getHeightIterative());
        System.out.println(tree_6.getHeight());
        System.out.println();
    }
}
