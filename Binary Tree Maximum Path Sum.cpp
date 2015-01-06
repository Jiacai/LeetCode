class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int result = root->val;
        maxPathSumRe(root, result);
        return result;
    }
	
    int maxPathSumRe(TreeNode *root, int &result) {
        if (root == NULL) {
            return 0;
        }
        int leftMax = maxPathSumRe(root->left, result);
        int rightMax = maxPathSumRe(root->right, result);
        result = max(result, root->val + max(0, leftMax) + max(0, rightMax));
        int sum = max(0, max(leftMax, rightMax)) + root->val;
        return sum;
    }
};
