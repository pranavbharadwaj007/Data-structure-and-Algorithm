
// Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int median=0;
        if(n&1){
            median=nums[n/2];
        }
        else{
            median=(nums[n/2]+nums[(n/2-1)])/2;
        }
        int res=0;
        for(auto &it:nums){
            res+=abs(median-it);
        }
        return res;
    }
};
