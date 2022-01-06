#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,q;
const int maxi=2e5+5;
vector<int> adj[maxi];
int sizes[maxi];

void dfs1(int u,int p){
sizes[u]=1;
for(auto x:adj[u]){
  if(x!=p){
    dfs1(x,u);
    sizes[u]+=sizes[x];
  }
}
}
 int dfs2(int u,int p){
   for(auto x:adj[u]){
     if(x!=p){
       if((sizes[x]*2)>n){
        return dfs2(x,u);
       }
     }
   }
   return u;
 }

int main() {
  
  cin>>n;
 for(int i=0;i<(n-1);i++){
   int a,b;
   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);
 }

  dfs1(1,1);
  cout<<dfs2(1,1)<<endl;
  cout<<endl;

 return 0;
}
