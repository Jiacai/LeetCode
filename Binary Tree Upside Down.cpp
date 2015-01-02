class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }
        root = stk.top();
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            if (node->left != NULL) {
                node->left->right = node;
                node->left->left = node->right;
                node->left = NULL;
                node->right = NULL;
            }
        }
        return root;
    }
};
