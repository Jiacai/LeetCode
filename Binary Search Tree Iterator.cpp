class BSTIterator {
public:
    stack<TreeNode *> path;
    
    BSTIterator(TreeNode *root) {
        path = stack<TreeNode *>();
        TreeNode *node = root;
        while (node != NULL) {
            path.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = path.top();
        path.pop();
        int ret = node->val;
        if (node->right != NULL) {
            node = node->right;
            path.push(node);
            while (node->left != NULL) {
                node = node->left;
                path.push(node);
            }
        }
        return ret;
    }
};
