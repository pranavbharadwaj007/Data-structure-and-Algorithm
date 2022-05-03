
// Link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                mini=min(mini,nums[i]);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                maxi=max(nums[i],maxi);
            }
        }
        if(mini==INT_MAX && maxi==INT_MIN)return 0;
        int s=0,e=n-1;
        for(;s<n;s++){
            if(nums[s]>mini)break;
        }
        for(;e>=0;e--){
            if(nums[e]<maxi)break;
        }
        return e-s+1;
    }
};
