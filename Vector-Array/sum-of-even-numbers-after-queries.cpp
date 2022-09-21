
// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int evsum=0;
        for(auto it:nums){
            if((it%2)==0)evsum+=it;
        }
        for(auto it:queries){
            int ind=it[1];
            int val=it[0];
            if(nums[ind]%2==0)evsum-=nums[ind];
            nums[ind]+=val;
            if(nums[ind]%2==0)evsum+=nums[ind];
            res.push_back(evsum);
        }
        return res;
    }
};
