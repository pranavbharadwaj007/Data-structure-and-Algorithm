class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>vec;
        while(head){
            vec.push_back(head->val);
            head=head->next;
        }
        int i=0,j=vec.size()-1;
        int ans=INT_MIN;
        while(i<j){
            int sum=vec[i++]+vec[j--];
            ans=max(ans,sum);
            
        }
        return ans;
    }
};
