public class Solution {
    public boolean isBalanced(TreeNode root) {
        boolean[] balanced = new boolean[1];
        balanced[0] = true;
        getHeight(root, balanced);
        return balanced[0];
    }
     
    public int getHeight(TreeNode root, boolean[] balanced){
        if (root == null) return 0;
        int hl = getHeight(root.left, balanced);
        int hr = getHeight(root.right, balanced);
        if (Math.abs(hl-hr) > 1) balanced[0] = false;
        return Math.max(hl, hr) + 1;
    }
}