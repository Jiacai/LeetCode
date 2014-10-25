class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            bool dup = false;
            while (next != NULL && next->val == cur->val) {
                dup = true;
                ListNode *tmp = next;
                next = next->next;
                cur->next = next;
                delete tmp;
            }
            if (dup) {
                ListNode *tmp = cur;
                prev->next = next;
                cur = next;
                delete tmp;
            } else {
                prev = cur;
                cur = next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
