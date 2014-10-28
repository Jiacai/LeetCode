class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *node = head;
        while (node != NULL) {
            RandomListNode *copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        RandomListNode *newHead = head->next;
        node = head;
        while (node != NULL) {
            RandomListNode *copy = node->next;
            copy->random = node->random == NULL ? NULL : node->random->next;
            node = copy->next;
        }
        
        node = head;
        while (node != NULL) {
            RandomListNode *copy = node->next;
            RandomListNode *next = copy->next;
            node->next = next;
            if (next != NULL) {
                copy->next = next->next;
            } else {
                copy->next = NULL;
            }
            node = next;
        }
        
        return newHead;
    }
};
