class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int result = root->val;
		maxPathSumRe(root, result);
		return result;
    }
	
	int maxPathSumRe(TreeNode *root, int &result) {
        if (root == NULL) return 0;
		int leftMax = maxPathSumRe(root->left, result);
		int rightMax = maxPathSumRe(root->right, result);
		int curMax = root->val;
		curMax = max(curMax, root->val + leftMax);
		curMax = max(curMax, root->val + rightMax);
		result = max(result, root->val + leftMax + rightMax);
		result = max(result, curMax);
		return curMax;
    }
};
