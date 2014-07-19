public class Solution {
    public ListNode rotateRight(ListNode head, int n) {
        if (head == null) return null;
        int len = 0;
        ListNode node = head;
        while (node != null)
        {
            node = node.next;
            len++;
        }
        n = n % len;
        if (n == 0) return head;
        n = len - n;
        node = head;
        ListNode last = null;
        while (n != 0)
        {
            last = node;
            node = node.next;
            n--;
        }
        last.next = null;
        ListNode end = node;
        while (end.next != null)
        {
            end = end.next;
        }
        end.next = head;
        return node;
    }
}