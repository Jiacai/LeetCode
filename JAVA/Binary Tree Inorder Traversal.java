public class Solution {
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode n = root;
        while (n!= null || !stack.empty()) {
            if (n!= null) {
                stack.push(n);
                n = n.left;
            }
            else {
                n = stack.pop();
                ans.add(n.val);
                n = n.right;
            }
        }
        return ans;
    }
}