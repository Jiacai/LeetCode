class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRe(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *buildTreeRe(vector<int> &preorder, int preleft, int preright, vector<int> &inorder, int inleft, int inright) {
        if (preleft > preright) return NULL;
        TreeNode *root = new TreeNode(preorder[preleft]);
        if (preleft == preright) return root;
        int rootIdxInorder = -1;
        for (int i = inleft; i <= inright; i++) {
            if (root->val == inorder[i]) {
                rootIdxInorder = i;
                break;
            }
        }
        int leftLen = rootIdxInorder - inleft;
        root->left = buildTreeRe(preorder, preleft + 1, preleft + leftLen, inorder, inleft, inleft + leftLen - 1);
        root->right = buildTreeRe(preorder, preleft + leftLen + 1, preright, inorder, rootIdxInorder + 1, inright);
        return root;
    }
};
