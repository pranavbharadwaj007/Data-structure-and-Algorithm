#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e3+10;
const int INF=1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];
int n,m;
int ans=0;
vector<pair<int,int>> mov={
{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}
};
bool isValid(int cx,int cy){
  if(cx>=0 && cy>=0 && cx<n && cy<m) return true;
  return false;
}

int bfs(){
  int mx=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      mx=max(mx,val[i][j]);
    }
  }
  queue<pair<int,int>>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mx==val[i][j]){
        q.push({i,j});
        lev[i][j]=0;
        vis[i][j]=1;
      }
    }
  }
  while(!q.empty()){
    pair<int,int> v=q.front();
    int vx=v.first;
    int vy=v.second;
    q.pop();
    for(auto mo:mov){
      int cx=mo.first+vx;
      int cy=mo.second+vy;
      if(!isValid( cx,cy))continue;
      if(vis[cx][cy])continue;
      q.push({cx,cy});
      lev[cx][cy]=lev[vx][vy]+1;
      vis[cx][cy]=1;
      ans=max(ans,lev[cx][cy]);
    }

  }
  return ans;
}

void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      vis[i][j]=0;
      lev[i][j]=INF;
    }
  }
  ans=0;
}
int main() {
 int t;
 cin>>t;
 while(t--){
   
  cin>>n>>m;
  reset();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>val[i][j];
    }
  }
  cout<<bfs()<<endl;
 }

 return 0;
}
