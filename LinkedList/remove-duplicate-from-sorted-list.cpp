// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* it=head;
        while(it!=nullptr && it->next!=nullptr){
            if(it->val==it->next->val){
                it->next=it->next->next;
            }
            else{
                it=it->next;
            }
        }
        return head;
    }
};
