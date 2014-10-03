class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode * node = head;
        while (node != NULL)
        {
            node = node->next;
            len++;
        }
        return buildTree(head, 0, len-1);
    }
     
    TreeNode *buildTree(ListNode *&node, int start, int end)
    {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *left = buildTree(node, start, mid-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        root->right = buildTree(node, mid+1, end);
        return root;
    }
};