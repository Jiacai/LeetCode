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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA = headA;
        ListNode *tailB = headB;
        int lengthA = getLength(headA, tailA);
        int lengthB = getLength(headB, tailB);
        if (tailA != tailB || tailA == NULL) {
            return NULL;
        }
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        int diff = abs(lengthA - lengthB);
        while (diff--) {
            if (lengthA > lengthB) {
                nodeA = nodeA->next;    
            } else {
                nodeB = nodeB->next;
            }
        }
        while (nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nodeA;
    }
    
    int getLength(ListNode *head, ListNode *&tail) {
        if (head == NULL) {
            tail = NULL;
            return 0;
        }
        int length = 1;
        ListNode *node = head;
        while (node->next != NULL) {
            node = node->next;
            length++;
        }
        tail = node;
        return length;
    }
};
