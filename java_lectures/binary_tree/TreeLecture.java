class TreeLecture{
    public static void main(String[] args){
        TreeNode tree_0 = new TreeNode(5, null, null);
        tree_0.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_0.getHeight());
        System.out.println();

        TreeNode tree_1 = new TreeNode(7, new TreeNode(4, null, null), null);
        tree_1.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_1.getHeight());
        System.out.println();

        TreeNode tree_2 = new TreeNode(12, new TreeNode(15, null, null),
                                       new TreeNode(16, null, null));

        tree_2.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_2.getHeight());
        System.out.println();

        TreeNode tree_3 = new TreeNode(12, new TreeNode(10, null, null),
                                       new TreeNode(17, null, new TreeNode(15,
                                       null, new TreeNode(15, null, null))));
        tree_3.preOrderWalkAndPrint();
        System.out.println();
        System.out.println(tree_3.getHeight());
        System.out.println();
    }
}
