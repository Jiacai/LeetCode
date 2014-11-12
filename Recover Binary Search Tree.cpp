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
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *node = root;
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        while (!stk.empty() || node != NULL) {
            if (node != NULL) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                // visit node
                if (prev != NULL) {
                    if (prev->val > node->val) {
                        if (first == NULL) {
                            first = prev;
                            second = node;
                        } else {
                            second = node;
                            break;
                        }
                    }
                }
                prev = node;
                node = node->right;
            }
        }
        if (first != NULL && second != NULL) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};
