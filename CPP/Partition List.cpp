class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* root = new ListNode(-1);
        ListNode* pivot = new ListNode(-1);
        ListNode* root_last = root;
        ListNode* pivot_last = pivot;
        ListNode* current = head;
        while (current != NULL)
        {
            if (current->val < x)
            {
                root_last->next = current;
                root_last = current;
            }
            else
            {
                pivot_last->next = current;
                pivot_last = current;
            }
            current = current->next;
        }
        root_last->next = pivot->next;
        pivot_last->next = NULL;
        return root->next;
    }
};