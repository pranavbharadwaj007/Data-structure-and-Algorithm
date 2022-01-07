// link : https://leetcode.com/problems/the-maze/

class Solution {
public:

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
       int n=maze.size();
       int m=maze[0].size();
       queue<pair<int,int>>q;
       q.push({start[0],start[1]});

       int vis[n][m];
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              vis[i][j]=0;
          }
      }
       vis[start[0]][start[1]]=1;
       while(!q.empty()){
           int x=q.front().first;
           int y=q.front().second;
                q.pop();
                if(x==destination[0] && y==destination[1]){
                    return true;
                }

           int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int dis=0;dis<4;dis++){
                int newx=x;
                int newy=y;
                while(newx>=0 && newx < n && newy >=0 && newy < m && maze[newx][newy]==0){
                    newx+=dx[dis];
                    newy+=dy[dis];
                }
                newx-=dx[dis];
                newy-=dy[dis];
                if(vis[newx][newy]==0){
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
       }
       return false;
    }
};
