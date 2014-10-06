/**
 * Annie's solution is more consistent
 */ 

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
    
    bool isBalanced_1(TreeNode *root) {
        int height = 0;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height){
        if (!root) return true;
        
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedRe(root->left, leftHeight)) return false;
        if (!isBalancedRe(root->right, rightHeight)) return false;
        if (abs(leftHeight-rightHeight) > 1) return false;
        
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};
