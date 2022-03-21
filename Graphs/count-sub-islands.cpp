// Link : https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n,int m,int i,int j,int &flag){
        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j]==0 ){
            return;
        }
        grid2[i][j]=0;
        if(grid1[i][j]==0)flag=0;
        dfs(grid1,grid2,n,m,i-1,j,flag);
        dfs(grid1,grid2,n,m,i+1,j,flag);
        dfs(grid1,grid2,n,m,i,j-1,flag);
        dfs(grid1,grid2,n,m,i,j+1,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    int flag=1;
                   // cout<<i<<" "<<j<<endl;
                    dfs(grid1,grid2,n,m,i,j,flag);
                    cnt+=flag;
                }
            }
        }
        return cnt;
    }
};
