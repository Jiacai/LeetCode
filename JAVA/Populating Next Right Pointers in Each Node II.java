public class Solution {
    public void connect(TreeLinkNode root) {
        if (root != null) root.next = null;
        TreeLinkNode first = root;
        TreeLinkNode last = null;
        while (first != null)
        {
            TreeLinkNode n = first;
            while (n != null)
            {
                if (n.left != null)
                {
                    if (last != null) last.next = n.left;
                    last = n.left;
                }
                if (n.right != null)
                {
                    if (last != null) last.next = n.right;
                    last = n.right;
                }
                n = n.next;
            }
            first = getNextLevelFirst(first);
            last = null;
        }
    }
     
    private TreeLinkNode getNextLevelFirst(TreeLinkNode first)
    {
        if (first == null) return null;
        while (first.left == null && first.right == null && first.next != null)
        {
            first = first.next;
        }
        if (first.left == null && first.right == null)
        {
            return null;
        }
        else if (first.left != null)
        {
            return first.left;
        }
        else if (first.right != null)
        {
            return first.right;
        }
        return null;
    }
}