public class Solution {
    public void flatten(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode n = root;
        TreeNode last = null;
        while (n != null || !stack.empty()) {
            if (n != null) {
                if (last != null) {
                    last.left = null;
                    last.right = n; 
                }
                last = n;
                if (n.right != null) {
                    stack.push(n.right);
                }
                n = n.left;
            }
            else {
                n = stack.pop();
            }
        }
    }
}