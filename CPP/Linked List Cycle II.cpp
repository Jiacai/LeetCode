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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            if (fast == NULL || fast->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        ListNode *n1 = head;
        ListNode *n2 = slow;
        while (n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};