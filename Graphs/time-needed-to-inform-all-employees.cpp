
// Link : https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
   int ans=0,maxi=0;
   void dfs(vector<int>adj[],int id,vector<int>& informTime){
       maxi=max(maxi,ans);
       for(auto emp:adj[id]){
           ans+=informTime[id];
           dfs(adj,emp,informTime);
           ans-=informTime[id];
       }
   }
    int numOfMinutes(int n, int hid, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        dfs(adj,hid,informTime);
        return maxi;
    }
};
