
// Link : https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    bool dfs(int ind,vector<bool>&vis,vector<bool>&dfsvis,vector<bool>&res,vector<vector<int>>& graph){
        vis[ind]=true;
        dfsvis[ind]=true;
        for(auto it:graph[ind]){
            if(!vis[it]){
                if(dfs(it,vis,dfsvis,res,graph)){
                    return res[ind]=true;
                }
            }else if(vis[it] && dfsvis[it]){
                return res[ind]=true;
            }
        }
        dfsvis[ind]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<bool>vis(n,false),dfsvis(n,false),res(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,dfsvis,res,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(!res[i])ans.push_back(i);
        }
        return ans;
    }
};
