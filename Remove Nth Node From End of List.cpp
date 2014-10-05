/**
 * need to delete the to-be-deleted node
 */
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *node = head;
        ListNode *prev = dummy;
        ListNode *cur = head;
        while (n--) {
            node = node->next;
        }
        while (node != NULL) {
            node = node->next;
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
