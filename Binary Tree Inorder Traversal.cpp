class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> stk;
        vector<int> vec;
        TreeNode* node = root;
        while (not stk.empty() || node != NULL) {
            if (node != NULL) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                vec.push_back(node->val);
                node = node->right;
            }
        }
        return vec;
    }
};
