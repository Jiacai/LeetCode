class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode* prevTail = &dummy;
        ListNode *nextHead = head;
        ListNode *thisHead = head;
        bool done = false;
        while (!done) {
            for (int i = 0; i < k; i++) {
                if (nextHead == NULL) {
                    done = true;
                    break;
                }
                nextHead = nextHead->next;
            }
            if (!done) {
                ListNode *prev = NULL;
                ListNode *current = thisHead;
                while (current != nextHead) {
                    ListNode *next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }
                prevTail->next = prev;
                prevTail = thisHead;
                thisHead = nextHead;
            } else {
                prevTail->next = thisHead;
            }
        }
        return dummy.next;
    }
};
