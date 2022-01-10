// link : https://cses.fi/problemset/task/1668/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1e5+10;
vector<int>g[maxi];
int color[maxi];
bool mark[maxi];
bool isbip;
void bfs(int s,int c){
  queue<int>q;
  q.push(s);
  mark[s]=true;
  color[s]=c;
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    int child_color=!color[curr];
    for(auto v:g[curr]){
      if(!mark[v]){
        q.push(v);
        mark[v]=true;
        color[v]=child_color;
      }
      else if(color[v]!=child_color){
          isbip=false;
        return;
      }
    }

  }

}
int main() {
cin>>n>>m;
int cnt=0;
for(int i=0;i<m;i++){
  int a,b;
  cin>>a>>b;
  g[a].push_back(b);
  g[b].push_back(a);
}
memset(color,-1, sizeof color);
isbip=true;
for(int i=1;i<=n;i++){
  if(!mark[i]){
    bfs(i,0);
  }
}
if(isbip){
  for(int i=1;i<=n;i++){
    cout<<color[i]+1<<" ";
  }
  cout<<endl;
}
else{
  cout<<"IMPOSSIBLE"<<endl;
}
 
 return 0;
}
