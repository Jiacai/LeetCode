class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode *node = head;
        int len = 1;
        while (node->next != NULL) {
            node = node->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;
        ListNode *end = node;
        node = head;
        for (int i = 0; i < len - k - 1; i++) {
            node = node->next;
        }
        ListNode *newHead = node->next;
        node->next = NULL;
        end->next = head;
        return newHead;
    }
};
