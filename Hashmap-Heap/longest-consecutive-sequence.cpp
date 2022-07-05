
// Link : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int res=0;
        for(int num:nums){
            if(!st.count(num-1)){
                int currn=num;
                int count=1;
                while(st.count(currn+1)){
                    currn++;
                    count++;
                }
                res=max(res,count);
            }
        }
        return res;
    }
};
