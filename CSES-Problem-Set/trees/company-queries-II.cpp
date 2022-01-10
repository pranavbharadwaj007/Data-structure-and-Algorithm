#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,q;
const int lg=22,maxi=2e5+5;
int timer;
int tin[maxi],tout[maxi];
vector<int> adj[maxi];
int up[maxi][lg+1];
void dfs(int v,int p,int d){
  tin[v]=++timer;
  up[v][0]=p;
  for(int i=1;i<=lg;i++){
    up[v][i]=up[up[v][i-1]][i-1];
  }
  for(int u:adj[v]){
      if(u!=p){
        dfs(u,v,d+1);
      }
  }
  tout[v]=++timer;
}
bool isAnc(int u,int v){
  return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
int lca(int a,int b){
  if(isAnc(a,b)){
    return a;
  }
   if(isAnc(b,a)){
    return b;
  }
  for(int i=lg;i>=0;i--){
    if(!isAnc(up[a][i],b)){
      a=up[a][i];
    }
  }
  return up[a][0];
}
int main() {

  cin>>n>>q;
  for(int i=2;i<=n;i++){
    int a;
    cin>>a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  dfs(1,1,0);
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<lca(a,b)<<endl;
  }

 return 0;
}
