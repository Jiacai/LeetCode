class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesRe(1, n);
    }
    
    vector<TreeNode *> generateTreesRe(int x, int y) {
        vector<TreeNode *> result;
        if (x > y) {
            result.push_back(NULL);
        } else {
            for (int k = x; k <= y; k++) {
                vector<TreeNode*> left = generateTreesRe(x, k - 1);
                vector<TreeNode*> right = generateTreesRe(k + 1, y);
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        TreeNode *root = new TreeNode(k);
                        root->left = left[i];
                        root->right = right[j];
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};
