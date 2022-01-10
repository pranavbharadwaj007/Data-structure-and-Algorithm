#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,q;
const int lg=22,maxi=2e5+5;
int timer;
int tin[maxi],tout[maxi];
vector<int> adj[maxi];
int up[maxi][lg+1];
int dep[maxi];
void dfs(int v,int p,int d){
  tin[v]=++timer;
  dep[v]=d;
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
int getDist(int n1,int n2){
  return dep[n1]+dep[n2]-2*dep[lca(n1,n2)];
}
int main() {

  cin>>n>>q;
  for(int i=0;i< n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,1,0);
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<getDist(a,b)<<endl;
  }

 return 0;
}
