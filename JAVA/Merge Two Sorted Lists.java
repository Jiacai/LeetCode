public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode root = null;
        ListNode n = null;
        while (l1 != null & l2 != null) {
            ListNode tmp = null;
            if (l1.val < l2.val) {
                tmp = new ListNode(l1.val);
                l1 = l1.next;
            }
            else {
                tmp = new ListNode(l2.val);
                l2 = l2.next;
            }
            if (root == null) {
                root = tmp;
                n = tmp;
            }
            else {
                n.next = tmp;
                n = tmp;
            }
        }
        if (l1 != null || l2 != null) {
            ListNode l = l1 != null ? l1 : l2;
            while (l != null) {
                ListNode tmp = new ListNode(l.val);
                l = l.next;
                if (root == null) {
                    root = tmp;
                    n = tmp;
                }
                else {
                    n.next = tmp;
                    n = tmp;
                }
            }
        }
        return root;
    }
}