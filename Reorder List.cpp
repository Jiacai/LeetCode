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
};