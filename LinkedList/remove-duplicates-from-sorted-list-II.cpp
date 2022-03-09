class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>mp;
        ListNode* tem=head;
        while(tem!=NULL){
            mp[tem->val]++;
            tem=tem->next;
        }
        tem=head;
          
        ListNode* nhead=new ListNode(-1);
         ListNode* res=nhead;
        while(tem!=NULL){
            
            if(mp[tem->val]==1){
                //cout<<mp[tem->val]<<endl;
               
                nhead->next=tem;
                nhead=nhead->next;
            }
            
            tem=tem->next;
           // cout<<res->next->val;
        }
          nhead->next=NULL;
        return res->next;
    }
};
