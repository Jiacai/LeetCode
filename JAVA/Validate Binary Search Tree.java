public class Solution {
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode n = root;
        int last = Integer.MIN_VALUE;
        while (n != null || !stack.empty()) {
            if (n != null) {
                stack.push(n);
                n = n.left;
            }
            else {
                n = stack.pop();
                // visit n
                if (n.val <= last) return false;
                last = n.val;
                n = n.right;
            }
        }
        return true;
    }
}