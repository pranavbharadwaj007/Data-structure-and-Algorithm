// link : https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mini=INT_MAX;
        for(int it:nums){
            if(it%2==1)it=it*2;
            mini=min(it,mini);
            pq.push(it);
        }
        int differ=INT_MAX;
        while((pq.top()%2==0)){
            int maxi=pq.top();
            pq.pop();
            differ=min(differ,maxi-mini);
            mini=min(mini,maxi/2);
            pq.push(maxi/2);
        }
        return min(differ,pq.top()-mini);
    }
};
