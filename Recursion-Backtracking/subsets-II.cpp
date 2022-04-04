
// Link : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    void swd(int ind,vector<int> &s,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind;i<s.size();i++){
            if(i!=ind && s[i]==s[i-1])continue;
            ds.push_back(s[i]);
            swd(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>> ans;
        vector<int>ds;
        swd(0,s,ds,ans);
        return ans;
    }
};
