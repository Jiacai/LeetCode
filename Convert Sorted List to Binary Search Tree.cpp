class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *next = NULL;
        int len = getLength(head);
        return sortedListToBSTRe(head, len, next);
    }
    
    int getLength(ListNode *node) {
        int len = 0;
        while (node != NULL) {
            node = node->next;
            len++;
        }
        return len;
    }
    
    TreeNode *sortedListToBSTRe(ListNode *head, int len, ListNode *&next) {
        if (len == 0) {
            next = head;
            return NULL;
        }
        int mid = len / 2;
        ListNode *leftNext = NULL;
        TreeNode *left = sortedListToBSTRe(head, mid, leftNext);
        TreeNode *root = new TreeNode(leftNext->val);
        ListNode *rightNext = NULL;
        TreeNode *right = sortedListToBSTRe(leftNext->next, len - mid - 1, rightNext);
        root->left = left;
        root->right = right;
        next = rightNext;
        return root;
    }
};
