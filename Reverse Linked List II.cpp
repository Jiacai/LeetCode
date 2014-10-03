class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* current = head;
        ListNode* last = NULL;
        int i = 1;
        while (i != m && current != NULL)
        {
            last = current;
            current = current->next;
            i++;
        }
        ListNode* start1 = last;
        ListNode* start2 = current;
        last = current;
        current = current->next;
        i++;
        while (i != n+1 && current != NULL)
        {
            ListNode* tmp = current->next;
            current->next = last;
            last = current;
            current = tmp;
            i++;
        }
        if (start1 != NULL)
        {
            start1->next = last;
        }
        else
        {
            head = last;
        }
        if (start2 != NULL)
        {
            start2->next = current;
        }
        return head;
    }
};