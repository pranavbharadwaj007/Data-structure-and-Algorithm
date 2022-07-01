
 // Link : https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        sort(bt.begin(),bt.end(),comp);
        int ans=0;
        for(auto it:bt){
            if(ts<it[0]){
                ans+=(ts*(it[1]));
                ts=0;
            }else{
                ans+=(it[0]*it[1]);
                ts=ts-it[0];
            }
        }

        return ans;
    }
};
