
// Link : https://leetcode.com/problems/max-number-of-k-sum-pairs/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i =0;
        int j =nums.size()-1;
        int count =0;
        while(i<j){
            if(nums[i]+nums[j]>k){
                j--;
                continue;
            }
            if(nums[i]+nums[j]==k){
                count++;
                i++;
                j--;
                continue;
            }
            
            if(nums[i]+nums[j]<k){
                i++;
                continue;
            }
            
        }
        
        return count;
        
    }
};
