class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode* n = root;
        stack<TreeNode*> st;
        while (n != NULL || !st.empty()) {
            if (n != NULL) {
                ans.push_back(n->val);
                st.push(n);
                n = n->left;
            }
            else {
                n = st.top();
                st.pop();
                n = n->right;
            }
        }
        return ans;
    }
};