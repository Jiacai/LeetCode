class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        int thisLevel = 1;
        int nextLevel = 0;
        vector<int> level;
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            level.push_back(node->val);
            thisLevel--;
            if (node->left != NULL) {
                que.push(node->left);
                nextLevel++;
            }
            if (node->right != NULL) {
                que.push(node->right);
                nextLevel++;
            }
            if (thisLevel == 0) {
                if (result.size() % 2 == 1) {
                    reverse(level.begin(), level.end());
                }
                result.push_back(level);
                level.clear();
                thisLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return result;
    }
};
