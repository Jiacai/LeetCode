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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTRe(num, 0, num.size() - 1);
    }
    
    TreeNode *sortedArrayToBSTRe(vector<int> &num, int left, int right) {
        if (right < left) return NULL;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = sortedArrayToBSTRe(num, left, mid - 1);
        node->right = sortedArrayToBSTRe(num, mid + 1, right);
    }
};
