
// Link : leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(int i,int j,int n,int m,int mid,vector<vector<int>>& h,int vis[100][100]){
        if(i==n-1 && j==m-1)return true;
        vis[i][j]=1;
        bool res=false;
        for(auto it:dir){
            int nx=i+it.first;
            int ny=j+it.second;
            if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1 || abs(h[i][j]-h[nx][ny])>mid){
                continue;
            }
            res=res||dfs(nx,ny,n,m,mid,h,vis);
            
        }
        return res;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int s=0,e=INT_MAX,ans=INT_MAX,n=heights.size(),m=heights[0].size();
        while(s<=e){
            int mid=s+(e-s)/2;
            int v[100][100];
            memset(v,0,sizeof v);
            if(dfs(0,0,n,m,mid,heights,v)){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
