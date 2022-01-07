#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1005;
vector<pair<int,int>> mov={{0,1},{0,-1},{1,0},{-1,0}};
char mat[maxi][maxi];
bool vis[maxi][maxi];
bool isValid(int x,int y){
  return (x>=0 && y>=0 && x< n && y<m);
}
void dfs(int x,int y){
  vis[x][y]=true;
  for(auto it:mov){
    int i=it.first;
    int j=it.second;
    int nx=i+x;
    int ny=j+y;
    if(isValid(nx, ny)){
      if(!vis[nx][ny] && mat[nx][ny]=='.'){
        dfs(nx,ny);
      }
    }
  }
}
int main() {
cin>>n>>m;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    cin>>mat[i][j];
  }
}
int cnt=0;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
   if(!vis[i][j] && mat[i][j]=='.'){
     cnt++;
   //  cout<<i<<j<<endl;
     dfs(i,j);
   }
  }
}
cout<<cnt<<endl;
 return 0;
}
