
// Link : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int i=0;
        while(i<nums.size()){
            if(nums[i]!=i+1){
                int cnt=nums[i]-1;
                if(nums[i]!=nums[cnt]){
                    swap(nums[i],nums[cnt]);
                }else{
                    return nums[i];
                }
            }else{
                i++;
            }
        }
        return -1;
    }
};
