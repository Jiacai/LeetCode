struct ListNodeCompare {
    bool operator()(ListNode* lhs, ListNode* rhs) {
        return lhs->val > rhs->val;
    }
};


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(0);
        ListNode *prev = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> que;
        for (int i = 0; i < lists.size(); i++) {
          if (lists[i] != NULL) {
            que.push(lists[i]);
          }
        }
        while (!que.empty()) {
            ListNode* node = que.top();
            que.pop();
            prev->next = node;
            prev = node;
            if (node->next != NULL) {
              que.push(node->next);
            }
            node->next = NULL;
        }
        return dummy.next;
    }
    
};
