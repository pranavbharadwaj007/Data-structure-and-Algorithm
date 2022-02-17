class Solution {
public:
    void combi(int idx,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&tem){
        if(idx==nums.size()){
            if(target==0){
                ans.push_back(tem);
            }
            return;
        }
        if(nums[idx]<=target){
            tem.push_back(nums[idx]);
            combi(idx,nums,target-nums[idx],ans,tem);
            tem.pop_back();
        }
        combi(idx+1,nums,target,ans,tem);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>tem;
        combi(0,nums,target,ans,tem);
        return ans;
    }
};
