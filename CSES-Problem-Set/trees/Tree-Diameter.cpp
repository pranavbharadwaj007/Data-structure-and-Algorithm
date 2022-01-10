#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>adj[200005];
int d=0,x=0;
void dfs(int s,int p,int dep){
  for(auto c:adj[s]){
    if(c!=p) dfs(c,s,dep+1);
  }
if(dep>d)d=dep,x=s;
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
    dfs(x,0,0);
  cout<<d<<endl;
 return 0;
}
