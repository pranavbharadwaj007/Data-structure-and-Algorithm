
// Link : https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    static bool comp(vector<int>&vec1,vector<int>&vec2){
        return vec1[1]-vec1[0]>vec2[1]-vec2[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        sort(costs.begin(),costs.end(),comp);
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans+=costs[i][0];
            }else{
                ans+=costs[i][1];
            }
        }
        return ans;
    }
};
