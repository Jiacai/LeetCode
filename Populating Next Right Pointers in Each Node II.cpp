/*
 * Annie's solution has constant space
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
    
    void connect_1(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *cur = root;
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        while (cur) {
            pre = &dummy;
            pre->next = nullptr;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy.next;
        }
    }
};
