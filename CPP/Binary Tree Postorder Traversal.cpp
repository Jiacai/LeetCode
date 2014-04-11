class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = NULL;
        while (!st.empty()) {
            TreeNode* current = st.top();
            if (prev == NULL || prev->left == current || prev->right == current) {
                if (current->left != NULL) {
                    st.push(current->left);
                }
                else if (current->right != NULL) {
                    st.push(current->right);
                }
            }
            else if (prev == current->left) {
                if (current->right != NULL) {
                    st.push(current->right);
                }
            }
            else {
                ans.push_back(current->val);
                st.pop();
            }
            prev = current;
        }
        return ans;
    }
};