public class Solution {
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if (root == null) return ans;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int lastLevel = 1;
        int thisLevel = 0;
        boolean direction = true;
         
        ArrayList<Integer> row = new ArrayList<Integer>();
        while (queue.size() != 0)
        {
            TreeNode n = queue.poll();
            lastLevel--;
            if (n.left != null)
            {
                queue.offer(n.left);
                thisLevel++;
            }
            if (n.right != null)
            {
                queue.offer(n.right);
                thisLevel++;
            }
            row.add(n.val);
            if (lastLevel == 0)
            {
                lastLevel = thisLevel;
                thisLevel = 0;
                if (!direction)
                {
                    // reverse
                    int len = row.size();
                    for (int i = 0; i < len/2; i++)
                    {
                        int tmp = row.get(i);
                        row.set(i, row.get(len-1-i));
                        row.set(len-1-i, tmp);
                    }
                }
                direction = !direction;
                ans.add(row);
                row = new ArrayList<Integer>();
            }
        }
        return ans;
    }
}