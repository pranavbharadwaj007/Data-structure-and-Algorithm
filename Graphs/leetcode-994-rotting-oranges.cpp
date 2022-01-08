//link : https://leetcode.com/problems/rotting-oranges/

struct node{
    int x,y,z;
    node(int _x,int _y,int _z){
        x=_x;
        y=_y;
        z=_z; // z =time
        
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<node>q;
        int cnto=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                q.push(node(i,j,0));
                }
                if(grid[i][j]!=0){
                    cnto++;
                }
            }
        }
int ans=0;
        int cnt=0;
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int time=q.front().z;
            q.pop();
            cnt++;
            ans=max(ans,time);
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int dis=0;dis<4;dis++){
                int newx=x+dx[dis];
                int newy=y+dy[dis];
                
                if(newx>=0 && newx < n && newy >=0 && newy < m && grid[newx][newy]==1){
                    grid[newx][newy]=2;
                    q.push(node(newx,newy,time+1));
                }
            }
        }
        if(cnt==cnto){
            return ans;
        }
        return -1;
    }
};
