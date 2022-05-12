
// Link : https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    	 void findPermutation(vector<int> nums, vector<vector<int>> &result,int index){
        if(index >= nums.size()){
            result.push_back(nums);
            return;
        }
             unordered_set<int>st;
        for(int i=index; i<nums.size(); i++){
            if(st.find(nums[i])!=st.end()) continue;
            st.insert(nums[i]);
            swap(nums[index], nums[i]);
            findPermutation(nums, result, index+1);
            swap(nums[index], nums[i]); 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
             vector<vector<int>> result;
        findPermutation(nums, result ,0);
        return result;
    }
};
