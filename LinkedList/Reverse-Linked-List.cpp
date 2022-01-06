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
};
