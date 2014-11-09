/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *tail;
        flattenRe(root);
    }
    
    // return tail
    TreeNode* flattenRe(TreeNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->left == NULL && head->right == NULL) {
            return head;
        }
        TreeNode *leftTail = flattenRe(head->left);
        TreeNode *rightTail = flattenRe(head->right);
        TreeNode *tail;
        TreeNode *rightHead = head->right;
        if (head->left != NULL) {
            head->right = head->left;
            head->left = NULL;
            leftTail->right = rightHead;
            leftTail->left = NULL;
            tail = leftTail;
        }
        if (rightHead != NULL) {
            tail = rightTail;
        }
        return tail;
    }
};
