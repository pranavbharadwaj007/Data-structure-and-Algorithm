
https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        grid[0][0]=1;
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto it=q.front();
                q.pop();
                int nx=it.second.first;
                int ny=it.second.second;
                int po=it.first;
                if(nx==n-1 && ny==m-1)return po;
                for(auto pr:dir){
                   int nxk = nx+(pr.first);
                   int nyk = ny+(pr.second);
                    if(nxk>=0 && nyk>=0 && nxk<n && nyk<m && grid[nxk][nyk]==0){
                          q.push({po+1,{nxk,nyk}}); 
                        grid[nxk][nyk]=1;
                    }
                 
                }
             
            }
        }
        return -1;
    }
};
