class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* p=head;
        ListNode* pre=new ListNode(0);
        pre->next=p;
        head = pre;
        int c=0;
        ListNode* st;
        ListNode* ed;
          
        while(p!=NULL){
            c++;
            if (c==1){st = p;} //get start node of every k nodes
            if (c==k){
                ed = p;         // get end node of every k nodes
                ListNode *last=ed;  //store the list after the k nodes
                ListNode *nst=st;   //store the next node to be reversed
                while (st!=ed){     // reverse the k nodes
                    last = ed->next;
                    nst = st->next;
                    st->next = last;
                    ed->next = st;
                    st=nst;
                }
                pre->next = st;     //link to the previous list
                for (int i=0;i<k-1;i++){    //get the end of the k nodes
                    p=p->next;    
                }
                c=0;                //reset count = 0 
            }
            if (c==0){pre = p;}     //store the previous list
            p=p->next;              //go next nodes
        }
        return head->next;
    }
};