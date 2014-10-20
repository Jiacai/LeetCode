/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *prev = head;
		ListNode *node = head->next;
		while (node != NULL) {
			if (prev->val == node->val) {
				ListNode *tmp = node->next;
				delete node;
				node = tmp;
			} else {
				prev->next = node;
				prev = node;
				node = node->next;
			}
		}
		prev->next = NULL;
		return head;
    }
};
