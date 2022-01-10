#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,q;
const int lg=22,maxi=2e5+5;
int depth[maxi];
vector<int> adj[maxi];
int up[maxi][lg+1];
void dfs(int v,int p,int d){
  depth[v]=d;
  up[v][0]=p;
  for(int i=1;i<=lg;i++){
    up[v][i]=up[up[v][i-1]][i-1];
  }
  for(int u:adj[v]){
      if(u!=p){
        dfs(u,v,d+1);
      }
  }
}
int getParent(int a,int k){
  int ans=a;
  for(int i=0;i<lg;i++){
    if((1LL << i)&k){
      ans=up[ans][i];
    }
  }
  return ans;
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
   int node,dist;
   cin>>node>>dist;
   if(dist>depth[node]){
     cout<<-1<<endl;
   }
   else{
     cout<<getParent(node, dist)<<endl;
   }
 }

 return 0;
}
