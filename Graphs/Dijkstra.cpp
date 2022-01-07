#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>g[N];

void dijkstra(int s,int n){
  vector<int>vis(N,0);
  vector<int>distance(N,INF);
  set<pair<int,int>>st;
  st.insert({0,s});
  distance[s]=0;
  while(st.size()>0){
    auto node=*st.begin();
    int v=node.second;
    int dist=node.first;
    st.erase(st.begin());
    if(vis[v])continue;
    vis[v]=1;
    for(auto it:g[v]){
      int child_v=it.first;
      int wt=it.second;
      if(distance[v]+wt<distance[child_v]){
        distance[child_v]=distance[v]+wt;
        st.insert({distance[child_v],child_v});
      }
    }
  }
  for(int i=1;i<=n;i++){
  cout<<distance[i]<<" ";
}
}

int main() {
int n, m;
cin>>n>>m;
for(int i=0;i<m;i++){
  int x,y,wt;
  cin>>x>>y>>wt;
  g[x].push_back({y,wt});
}
 dijkstra(1,n);
 return 0;
}
