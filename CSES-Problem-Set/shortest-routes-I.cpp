#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=1e18;
int n,m;
vector<pair<int,int>>g[N];
vector<int> dijkstra(int s,int n){
  vector<int>vis(n+1,0);
  vector<int>distance(n+1,INF);
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
return distance;
}

signed main() {

cin>>n>>m;
for(int i=0;i<m;i++){
  int x,y,wt;
  cin>>x>>y>>wt;
  g[x].push_back({y,wt});
}
 vector<int>res=dijkstra(1,n);
 for(int i=1;i<=n;i++){
   cout<<res[i]<<" ";
 }
 cout<<endl;
 return 0;
}
