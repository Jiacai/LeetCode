public class Solution {
    public ArrayList<TreeNode> generateTrees(int n) {
        return generateTrees(1, n);
    }
     
    private ArrayList<TreeNode> generateTrees(int left, int right)
    {
        ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
        if (left > right)
        {
            ans.add(null);
            return ans;
        }
        for (int i = left; i <= right; i++)
        {
            ArrayList<TreeNode> lefts = generateTrees(left, i-1);
            ArrayList<TreeNode> rights = generateTrees(i+1, right);
            for (int j = 0; j < lefts.size(); j++)
            {
                for (int k = 0; k < rights.size(); k++)
                {
                    TreeNode root = new TreeNode(i);
                    root.left = lefts.get(j);
                    root.right = rights.get(k);
                    ans.add(root);
                }
            }
        }
        return ans;
    }
}