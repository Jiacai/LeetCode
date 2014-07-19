public class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length != postorder.length) return null;
        return buildTree(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }
     
    private TreeNode buildTree(int[] inorder, int inLow, int inHigh, int[] postorder, int postLow, int postHigh)
    {
        if (inHigh - inLow < 0) return null;
        TreeNode root = new TreeNode(postorder[postHigh]);
        int c = -1;
        for (c = inLow; c <= inHigh; c++)
        {
            if (inorder[c] == postorder[postHigh]) break;
        }
        // split into two parts
        int len = c - inLow;
        root.left = buildTree(inorder, inLow, c-1,
                            postorder, postLow, postLow+len-1);
        root.right = buildTree(inorder, c+1, inHigh,
                            postorder, postLow+len, postHigh-1);
        return root;
    }
}