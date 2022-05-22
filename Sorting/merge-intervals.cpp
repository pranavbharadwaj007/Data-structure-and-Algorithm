
// Link : https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end());
        vector<vector<int>>vec;
        int n=intv.size();
        auto it=intv[0];
        for(int i=1;i<n;i++){
            if(it[1]>=intv[i][0]){
                it[1]=max(it[1],intv[i][1]);
                
            }else{
                vec.push_back(it);
                it=intv[i];
            }
        }
        vec.push_back(it);
        return vec;  
    }
};
