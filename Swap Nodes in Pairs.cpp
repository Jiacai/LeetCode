class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode *a = prev->next;
            ListNode *b = a->next;
            a->next = b->next;
            b->next = a;
            prev->next = b;
            prev = a;
        }
        return dummy.next;
    }
};
