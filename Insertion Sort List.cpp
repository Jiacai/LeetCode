class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *o_dummy = new ListNode(0);
        ListNode *n_dummy = new ListNode(0);
        o_dummy->next = head;
        ListNode *last = n_dummy;
        while (o_dummy->next != NULL) {
            ListNode *prev = o_dummy;
            ListNode *node = prev->next;
            // find node with min val
            ListNode *min_node = node;
            ListNode *prev_node = prev;
            while (node != NULL) {
                if (node->val < min_node->val) {
                    min_node = node;
                    prev_node = prev;
                }
                node = node->next;
                prev = prev->next;
            }
            prev_node->next = min_node->next;
             
            // insert to new list
            min_node->next = NULL;
            last->next = min_node;
            last = min_node;
        }
        return n_dummy->next;
    }
};