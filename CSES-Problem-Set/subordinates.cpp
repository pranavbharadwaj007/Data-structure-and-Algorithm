#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxi = 2e5+7;
vector<int> adj[maxi];
int res[maxi];
void dfs(int v,int p){
  for(int x:adj[v]){
    if(x!=p){
      dfs(x,v);
      res[v]+=res[x]+1;
    }
  }
}

int main() {
int n;
cin>>n;
for(int i=2;i<=n;i++){
  int p;
  cin>>p;
  adj[p].push_back(i);
   adj[i].push_back(p);
}
dfs(1,-1);
for(int i=1;i<=n;i++){
  cout<<res[i]<<" ";
}
 return 0;
}
