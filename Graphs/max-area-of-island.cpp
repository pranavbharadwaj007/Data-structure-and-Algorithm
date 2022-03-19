
// DFS

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
           return 0;
       }
       if(grid[i][j]==0)return 0;
       grid[i][j]=0;
       return 1+(dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                maxi=max(maxi,dfs(grid,i,j));
            }
        }
    }
    
        return maxi;
    }
};

// BFS

class Solution {
public:
// BFS 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int maxi=0;
    vector<int>co={0,1,0,-1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                queue<pair<int,int>>q;
                q.push({i,j});
                int res=1;
                while(!q.empty()){
                    auto p=q.front();
                    q.pop();
              
                    for(int k=0;k<4;k++){
                    int nx=p.first+co[k];
                    int ny=p.second+co[k+1];
                    if(nx>=0 && ny>=0 && nx<n && ny < m && grid[nx][ny] ){
                        q.push({nx,ny});
                        grid[nx][ny]=0;
                        res++;
                    }
                    }
                    
                }
                maxi=max(maxi,res);
            }
            
        }
    }
    
        return maxi;
    }
};
