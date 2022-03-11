class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len) 
            cur = cur->next;
      
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
       
        head = cur->next;
        cur->next = NULL;
        
        
        return head; 
    }
};
