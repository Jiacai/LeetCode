class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSumRe(root, 0, sum);
    }
    
    bool hasPathSumRe(TreeNode *root, int current, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && current + root->val == sum)
            return true;
        return hasPathSumRe(root->left, current + root->val, sum)
                || hasPathSumRe(root->right, current + root->val, sum);
    }
};
