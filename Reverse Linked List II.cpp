class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *node = head;
        int i = 1;
        for (; i < m; i++) {
            prev = prev->next;
            node = node->next;
        }
        ListNode *tail = node;
        ListNode *next = node->next;
        for (; i < n; i++) {
            ListNode *tmp = next->next;
            next->next = node;
            prev->next = next;
            tail->next = tmp;
            node = next;
            next = tmp;
        }
        return dummy.next;
    }
};
