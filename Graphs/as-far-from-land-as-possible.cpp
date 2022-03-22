// Link : https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                   q.push({i,j});
            }
        }
        if(q.size()==0 || q.size()==(n*m)){
            return -1;
        }
        int lev=-1;
        while(q.size()>0){
            lev++;
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=it.first+dir[i].first;
                    int ny=it.second+dir[i].second;
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==1){
                        continue;
                    }
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return lev;
    }
};
