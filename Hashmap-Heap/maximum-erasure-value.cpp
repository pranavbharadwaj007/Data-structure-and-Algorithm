
// Link : https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(j<nums.size()){
            int ele=nums[j];
            sum+=ele;
            mp[ele]++;
            j++;
            while(mp[ele]>1){
                int prev=nums[i];
                mp[prev]--;
                sum-=prev;
                i++;
            }
            
            ans=max(ans,sum);
        }
        return ans;
    }
};
