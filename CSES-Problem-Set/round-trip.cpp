// link : https://cses.fi/problemset/task/1669/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1e5+5;
vector<int>g[maxi];
stack<int>st;
vector<int>res;
bool vis[maxi];
void dfs(int node,int parent){
  vis[node]=true;
  st.push(node);
  for(auto x:g[node]){
    if(x!=parent){
      if(!vis[x]){
        dfs(x,node);
      }
      else if(size(res)==0){
        res.push_back(x);
        while(!st.empty() && (st.top()!=x)){
          res.push_back(st.top());
          st.pop();
        }
         res.push_back(x);
      }
    }
  }
  if(st.top()==node)st.pop();
}
int main() {
cin>>n>>m;
int cnt=0;
int a,b;
for(int i=0;i<m;i++){
  cin>>a>>b;
  g[a].push_back(b);
  g[b].push_back(a);
}
for(int i=1;i<=n;i++){
  if(!vis[i]){
    dfs(i,-1);
  }
}
if(size(res)){
  cout<<size(res)<<endl;
  for(auto r:res){
    cout<<r<<" ";
  }
  cout<<endl;
}
else{
  cout<<"IMPOSSIBLE"<<endl;
}

 return 0;
}
