
// Link : https://leetcode.com/problems/find-pivot-index/
// O(n) time and space

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>suf(nums.size()+1);
        suf[nums.size()]=0;
        for(int i=nums.size()-1;i>=0;i--){
            suf[i]=nums[i]+suf[i+1];
        }
   
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum==suf[i+1]){
                return i;
                
            }
            sum=sum+nums[i];
        }
        return -1;
    }
};

// optimal  O(1) space O(n) time

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightsum = 0;
        for(int i=nums.size()-01;i>=0;i--)
            rightsum+=nums[i];
        int leftsum =0;
        for(int i=0;i<nums.size();i++)
        {
            if(leftsum == rightsum - nums[i])
                return i;
            leftsum += nums[i];
            rightsum-=nums[i];
        }
        return -1;
    }
};
