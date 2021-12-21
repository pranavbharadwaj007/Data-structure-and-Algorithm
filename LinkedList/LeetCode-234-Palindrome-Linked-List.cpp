class Solution {
public:
        ListNode* reverseList(ListNode* head) {
        ListNode* cnt =head;
        ListNode* prev=nullptr;
        while(head){
            head=head->next;
            cnt->next=prev;
            prev=cnt;
            cnt=head;
        }
        return prev;
    }
        ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
               slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
         ListNode* mid=middleNode(head);
        ListNode* nhead=mid->next;
        mid->next = nullptr;
        nhead=reverseList(nhead);
        ListNode* i=head;
        ListNode* j=nhead;
        bool ans=true;
        while(i!=NULL && j!=NULL){
            if(i->val!=j->val){
                ans=false;
                break;
            }
            i=i->next;
            j=j->next;
            
        }
           nhead=reverseList(nhead);
        mid->next=nhead;
        return ans;
        
    }
};
