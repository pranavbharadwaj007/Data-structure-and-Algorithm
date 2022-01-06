#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,q;
const int maxi=2e5+5;
vector<int> adj[maxi];
int values[maxi],ans[maxi];

set<int> dfs(int c,int p){
  set<int>st;
  st.insert(values[c]);
  for(auto x:adj[c]){
    if(x!=p){
    set<int> st_child=dfs(x,c);
    if(size(st)>size(st_child)){
      for(int it:st_child){
        st.insert(it);
      }
    }else{
      for(int it:st){
        st_child.insert(it);
      }
      swap(st,st_child);
    }
    }
  }
  ans[c]=size(st);
  return st;
}

int main() {
  cin>>n;
  for(int i=1;i<=n;i++){
   cin>>values[i];
  }
  for(int i=0;i< (n-1);i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,1);
  for(int i=1;i<=n;i++){
      cout<<ans[i]<<" ";
  }
  cout<<endl;

 return 0;
}
