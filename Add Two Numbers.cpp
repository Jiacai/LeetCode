class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode *prev = &dummy;
        while (l1 != NULL || l2 != NULL) {
            int val = carry;
            if (l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            prev->next = new ListNode(val % 10);
            prev = prev->next;
        }
        if (carry == 1) {
            prev->next = new ListNode(1);
        }
        return dummy.next;
    }
};
