public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        ListNode last = head;
        ListNode current = head.next;
        while (current != null)
        {
            if (last.val == current.val)
            {
                last.next = current.next;
                current = last.next;
            }
            else
            {
                last = current;
                current = last.next;
            }
        }
        return head;
    }
}