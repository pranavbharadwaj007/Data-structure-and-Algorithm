//link : https://cses.fi/problemset/task/1193/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1005;
vector<vector<char>> mov={{0,1,'R'},{0,-1,'L'},{1,0,'D'},{-1,0,'U'}};
char mat[maxi][maxi];
char vis[maxi][maxi];
bool isValid(int x,int y){
  return (x>=0 && y>=0 && x< n && y<m);
}
void bfs(int a,int b){
  queue<pair<int,int>>q;
  q.push(make_pair(a,b));
  vis[a][b]='_';
  while(!q.empty()){
    auto x=q.front();
    q.pop();
    int i=x.first;
    int j=x.second;
    for(auto it:mov){
      int nx=i+it[0];
      int ny=j+it[1];
      if(isValid(nx,ny)){
        if(!vis[nx][ny] && mat[nx][ny]!='#'){
          q.push(make_pair(nx,ny));
          vis[nx][ny]=it[2];
        }
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
memset(vis,0,sizeof vis);
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(!vis[i][j] && mat[i][j]=='A'){
      bfs(i,j);
    }
  }
}
string res="";
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(mat[i][j]=='B' && vis[i][j]){
      int dx=i;
      int dy=j;
      while(vis[dx][dy]!='_'){
          for(auto it:mov){
          if(it[2]==vis[dx][dy]){
              dx-=it[0];
              dy-=it[1];
              res+=it[2];
          }
        }
      }
    }
  }
}

reverse(res.begin(),res.end());
if(size(res)){
  cout<<"YES"<<endl;
  cout<<size(res)<<endl;
  cout<<res<<endl;
}
else{
  cout<<"NO"<<endl;

}

return 0;
}

