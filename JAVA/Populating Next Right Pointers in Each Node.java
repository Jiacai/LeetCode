
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode left = root;
        TreeLinkNode n = null;
        while (left != null && left.left != null && left.right != null)
        {
            n = left;
            while (n != null)
            {
                n.left.next = n.right;
                if (n.next != null)
                {
                    n.right.next = n.next.left;
                }
                n = n.next;
            }
            left = left.left;
        }
    }
}