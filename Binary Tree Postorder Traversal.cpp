/**
 * I like solution 2 better as it's simpler
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        postorderTraversal_1(root);
    }
    
    vector<int> postorderTraversal_1(TreeNode *root) {
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
    
    vector<int> postorderTraversal_2(TreeNode *root) {
        vector<int> vec;
        stack<pair<TreeNode*, int>> stk;
        TreeNode* node = root;
        while (not stk.empty() || node != NULL) {
            if (node != NULL) {
                stk.push(make_pair(node, 1));
                node = node->left;
            } else {
                if (stk.top().second == 1) {
                    stk.top().second = 2;
                    node = stk.top().first->right;
                } else {
                    vec.push_back(stk.top().first->val);
                    stk.pop();
                    node = NULL;
                }
            }
        }
        return vec;
    }
};
