class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        result.clear();
        vector<int> path;
        pathSumRe(root, path, 0, sum);
        return result;
    }
    
    void pathSumRe(TreeNode *root, vector<int> &path, int current, int sum) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && current + root->val == sum) {
            result.push_back(path);
        }
        pathSumRe(root->left, path, current + root->val, sum);
        pathSumRe(root->right, path, current + root->val, sum);
        path.pop_back();
    }
};
