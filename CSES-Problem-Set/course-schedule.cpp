#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=1e18;
int n,m;
vector<int>adj[N];
bool detectCycle(vector<int>&vis,int v){
if(vis[v]==2)return true;
vis[v]=2;
for(auto it:adj[v]){
  if(vis[it]!=1){
    if(detectCycle(vis,it)){
      return true;
    }
  }
}
  vis[v]=1;
  return false;
}
bool cycleDect(int n){
  vector<int> vis(n+1,0);
  for(int i=0;i<n;i++){
    if(!vis[i]){
      if(detectCycle(vis, i)){
        return true;
      }
    }
  }
  return false;
}
void topoDfs(int v,vector<int>& visited,vector<int>& res){
   visited[v]=1;
   for(auto it:adj[v]){
     if(!visited[it]){
       topoDfs(it,visited, res);
     }
   }
res.push_back(v);
}
signed main() {
cin>>n>>m;
vector<pair<int,int>>g[n+1];
for(int i=0;i<m;i++){
  int x,y,wt;
  cin>>x>>y;
  adj[x].push_back(y);
}
bool isCy=cycleDect(n);
if(isCy){
  cout<<"IMPOSSIBLE"<<endl;
}
else{
 vector<int> visited(n+5,0);
 vector<int>res;
 for(int i=1;i<=n;i++){
   if(!visited[i]){
   topoDfs(i,visited,res);
   }
 }
 reverse(res.begin(),res.end());
 for(auto y:res){
   cout<<y<<" ";
 }
 cout<<endl;
}
 return 0;
}

