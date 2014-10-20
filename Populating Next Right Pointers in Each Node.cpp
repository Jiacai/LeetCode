/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> que;
		que.push(root);
		int curLevel = 1;
		int nextLevel = 0;
		TreeLinkNode* dummy = new TreeLinkNode(0);
		TreeLinkNode* prev = dummy;
		while (not que.empty()) {
			TreeLinkNode* node = que.front();
			que.pop();
			if (node->left != NULL) {
				que.push(node->left);
				nextLevel++;
			}
			if (node->right != NULL) {
				que.push(node->right);
				nextLevel++;
			}
			curLevel--;
			prev->next = node;
			prev = node;
			if (curLevel == 0) {
				curLevel = nextLevel;
				nextLevel = 0;
				prev = dummy;
				node->next = NULL;
			}
		}
		delete dummy;
    }
};
