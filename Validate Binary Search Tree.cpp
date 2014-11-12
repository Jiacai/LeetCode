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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode*> stk;
        TreeNode *node = root;
        TreeNode *prev = NULL;
        while (!stk.empty() || node != NULL) {
            if (node != NULL) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                // visit
                if (prev != NULL && prev->val >= node->val)
                    return false;
                prev = node;
                node = node->right;
            }
        }
        return true;
    }
};
