public class Solution {
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode n = root;
        TreeNode last = null;
        TreeNode current = null;
        TreeNode n1 = null;
        TreeNode n2 = null;
        while (n != null || !stack.empty()) {
            if (n != null) {
                stack.push(n);
                n = n.left;
            }
            else {
                n = stack.pop();
                // visit n
                last = current;
                current = n;
                if (last != null && current != null && last.val > current.val) {
                    if (n1 == null) {
                        n1 = last;
                        n2 = current;
                    }
                    else {
                        n2 = current;
                    }
                }
                n = n.right;
            }
        }
        if (n1 != null && n2 != null) {
            int tmp = n1.val;
            n1.val = n2.val;
            n2.val = tmp;
        }
    }
}