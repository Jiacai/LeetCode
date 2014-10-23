/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        queue<TreeNode *> que;
        que.push(root);
        int thisLevel = 1;
        int nextLevel = 0;
        vector<int> level;
        while (!que.empty()) {
            TreeNode * node = que.front();
            que.pop();
            level.push_back(node->val);
            if (node->left != NULL) {
                que.push(node->left);
                nextLevel++;
            }
            if (node->right != NULL) {
                que.push(node->right);
                nextLevel++;
            }
            thisLevel--;
            if (thisLevel == 0) {
                result.push_back(level);
                thisLevel = nextLevel;
                nextLevel = 0;
                level.clear();
            }
        }
        return result;
    }
};
