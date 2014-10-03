/**
Two way to write the recursive solution, similar
*/

class Solution {
public:
    int minDepth(TreeNode *root) {
      return minDepth_1(root);
    }
    
    int minDepth_1(TreeNode *root) {
      if (root == NULL)
          return 0;
      int depth = 1 << 30;
      minDepthRe(root, 1, depth);
      return depth;
    }
    
    void minDepthRe(TreeNode *root, int currentDepth, int &minDepth) {
        if (root->left == NULL && root->right == NULL) {
            minDepth = min(minDepth, currentDepth);
        }
        if (root->left != NULL) {
            minDepthRe(root->left, currentDepth + 1, minDepth);
        }
        if (root->right != NULL) {
            minDepthRe(root->right, currentDepth + 1, minDepth);
        }
    }
    
    int minDepth_2(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        else if (!root->left)
            return 1 + minDepth_1(root->right);
        else if (!root->right)
            return 1 + minDepth_1(root->left);
        else
            return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
    }
};
