class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        calculate(root, 0, sum);
        return sum;
    }
     
    void calculate(TreeNode *root, int currentSum, int& sum)
    {
        if (root == NULL) return;
        currentSum = currentSum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            sum += (currentSum);
        }
        else
        {
            calculate(root->left, currentSum, sum);
            calculate(root->right, currentSum, sum);
        }
    }
};