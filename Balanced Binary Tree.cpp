class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool balanced = true;
        getHeightRe(root, balanced);
        return balanced;
    }
    
    int getHeightRe(TreeNode *root, bool &balanced) {
        if (root == NULL)
            return 0;
        int left = getHeightRe(root->left, balanced);
        int right = getHeightRe(root->right, balanced);
        int height = max(left, right) + 1;
        if (abs(left - right) > 1) {
            balanced = false;
        };
        return height;
    }
};
