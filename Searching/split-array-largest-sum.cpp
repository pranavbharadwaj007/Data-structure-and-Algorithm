
// Link : https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start=0;
        int end=0;
        
        for(int i=0;i<nums.size();i++){
            start=max(start,nums[i]);
            end+=nums[i];
        }
        while(start<end){
            int mid=start + (end-start)/2;
            int sum=0;
            int pieces=1;
            for(int x:nums){
                if(sum+x>mid){
                    sum=x;
                    pieces++;
                }
                else{
                    sum+=x;
                }
            }
            if(pieces>m){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return end;
    }
};
