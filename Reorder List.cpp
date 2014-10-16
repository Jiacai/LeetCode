#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
class Solution {
public:
    ListNode * reverseList(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;
        while (current != NULL) {
            ListNode *tmp = current->next;
            current->next = (prev == dummy ? NULL : prev);
            prev = current;
            current = tmp;
        }
        delete dummy;
        return prev;
    }
    
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            if (fast == NULL || fast->next == NULL) break;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // disconnect the list from after slow
        ListNode *second = slow->next;
        slow->next = NULL;
        second = reverseList(second);
        ListNode *first = head;
        while (first != NULL && second != NULL) {
            ListNode *first_next = first->next;
            ListNode *second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
        if (second != NULL) {
            second->next = NULL;
        }
    }    
    
    void reorderList_2(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *fast = head->next;
        ListNode *slow = head;
        // fast will finally stop at an even position 1->2->3->4
        while (fast!= NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow;
        ListNode *cur = mid->next;
        while (cur->next) {
            ListNode *mov = cur->next;
            cur->next = mov->next;
            mov->next = mid->next;
            mid->next = mov;
        }
        ListNode *p2 = mid->next;
        mid->next = NULL;
        ListNode *p1 = head;
        while (p1 && p2) {
            ListNode *tmp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = tmp;
        }
    }
};
