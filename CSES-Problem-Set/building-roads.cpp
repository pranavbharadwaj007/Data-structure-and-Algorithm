#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1e5+10;
vector<int>g[maxi];
bool vis[maxi];
void dfs(int x){
  vis[x]=true;
  for(auto c:g[x]){
    if(!vis[c]){
      dfs(c);
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
vector<int>v;
for(int i=1;i<=n;i++){
  if(!vis[i]){
    dfs(i);
    cnt++;
    v.push_back(i);
    }
   
  }
  cout<<cnt-1<<endl;
  for(int i=1;i<size(v);i++){
    cout<<v[i-1]<<" "<<v[i]<<endl;
  }
 return 0;
}
