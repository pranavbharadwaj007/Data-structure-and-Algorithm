class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            ListNode* nxt=curr->next->next;
            ListNode* seco=curr->next;
            seco->next=curr;
            curr->next=nxt;
            prev->next=seco;
            
            prev=curr;
            curr=nxt;
            
        }
        return dummy->next;
    }
};
