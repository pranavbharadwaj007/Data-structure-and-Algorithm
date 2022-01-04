#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> adj[200005];
int ans[200005];
int d=0,x=0;
int d1=0,x1=0;
void dfs(int s,int p,int dep){
  for(auto c:adj[s]){
    if(c!=p) dfs(c,s,dep+1);
  }
if(dep>d)d=dep,x=s;
}
void dfs3(int s,int p,int dep){
  for(auto c:adj[s]){
    if(c!=p) dfs3(c,s,dep+1);
  }
if(dep>d1)d1=dep,x1=s;
}
void dfs2(int s,int p,int dep){
  ans[s]=max(ans[s],dep);
  for(auto c:adj[s]){
    if(c!=p) dfs2(c,s,dep+1);
  }

}
int main() {
int n;
 cin>>n;
 for(int i=0;i<n-1;i++){
   int a,b;
   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);
 }
    dfs(1,0,0);
  // cout<<x<<endl;
    dfs3(x,0,0);
   // cout<<x1<<endl;
    dfs2(x,x,0);
    dfs2(x1,x1,0);

    for(int i=1;i<=n;i++){
      cout<<ans[i]<<" ";
    }
  cout<<endl;
 return 0;
}
