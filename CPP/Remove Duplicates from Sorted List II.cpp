class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pPrePre = dummy;
        if (pPrePre == NULL) return dummy->next;
        ListNode* pPre = pPrePre->next;
        if (pPre == NULL) return dummy->next;
        ListNode* pCur = pPre->next;
        if (pCur == NULL) return dummy->next;
        while (!(pPrePre == NULL || pPre == NULL || pCur == NULL) )// not end
        {
            bool eq = false;
            while (pCur != NULL && pPre->val == pCur->val)
            {
                eq = true;
                pPre->next = pCur->next;
                pCur = pCur->next;
            }
            if (eq)
            {
                pPrePre->next = pCur;
                pPre = pCur;
                if (pCur != NULL)
                {
                    pCur = pCur->next;
                }
            }
            else
            {
                pPrePre = pPre;
                pPre = pCur;
                if (pCur != NULL)
                {
                    pCur = pCur->next;
                }
            }
        }
        return dummy->next;
    }
};