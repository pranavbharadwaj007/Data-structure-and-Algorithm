
// Link : https://leetcode.com/problems/target-sum/

class Solution {
public:
    int eqtsum(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0 && nums[0]<=target)dp[0][nums[0]]=1;
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=target;tar++){
                int notak=dp[ind-1][tar];
                int tak=0;
                if(nums[ind]<=tar)tak=dp[ind-1][tar-nums[ind]];
                
                dp[ind][tar]=tak+notak;
            }
        }
        return dp[n-1][target];
    }
    

    int findTargetSumWays(vector<int>& nums, int target) {
        int sumi=0;
        for(auto it:nums){
            sumi+=it;
        }
        if(sumi-target<0 || (sumi-target)%2==1)return 0;
        int val= eqtsum(nums,(sumi-target)/2);
        
        return val;
    }
};
