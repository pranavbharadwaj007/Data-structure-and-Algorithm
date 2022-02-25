class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        vector<int>vec;
        ListNode* hi=head;
        ListNode* hit=new ListNode(-1);
        ListNode* headi=hit;
        while(hi!=NULL){
            if(hi->val==0){
                if(sum){
                hit->next=new ListNode(sum);
                    hit=hit->next;
              
                }
                 sum=0; 
            }else{
                sum+=hi->val;
            }
            hi=hi->next;
        }
        if(sum){
            hit->next=new ListNode(sum);
            hit=hit->next;
        }
        hit->next=NULL;

        return headi->next;
    }
};
