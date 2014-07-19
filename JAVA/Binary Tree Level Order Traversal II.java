public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int lastLevel = 1;
        int thisLevel = 0;
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        while (queue.size() != 0)
        {
            TreeNode n = queue.poll();
            lastLevel--;
            if (n != null)
            {
                tmp.add(n.val); 
                queue.offer(n.left);
                queue.offer(n.right);
                thisLevel += 2;
            }
            if (lastLevel == 0)
            {
                lastLevel = thisLevel;
                thisLevel = 0;
                if (tmp.size() != 0)
                {
                    ans.add(tmp);
                }
                tmp = new ArrayList<Integer>();
            }
        }
        int len = ans.size();
        for (int i = 0; i < len/2; i++)
        {
            tmp = ans.get(i);
            ans.set(i, ans.get(len - i - 1));
            ans.set(len - i - 1, tmp);
        }
 
        return ans;
    }
}