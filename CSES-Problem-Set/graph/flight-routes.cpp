// link : https://cses.fi/problemset/task/1196/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=1e18;
int n,m,k;
vector<vector<int>> dijkstra(int s,int n,vector<pair<int,int>>g[]){
  vector<vector<int>>distance(n+1);
  multiset<pair<int,int>>st;
  st.insert({0,s});
   
  while(st.size()>0){
    auto node=*st.begin();
    int v=node.second;
    int dist=node.first;
    st.erase(st.begin());
  
    if(size(distance[v])>=k)continue;
    distance[v].push_back(dist);
    for(auto it:g[v]){
      int child_v=it.first;
      int wt=it.second;
      st.insert({wt+dist,child_v});
    }
  }
return distance;
}
signed main() {
cin>>n>>m>>k;
vector<pair<int,int>>g[n+1];
for(int i=0;i<m;i++){
  int x,y,wt;
  cin>>x>>y>>wt;
  g[x].push_back({y,wt});
}
 vector<vector<int>>res=dijkstra(1,n,g);
 for(int i=0;i<k;i++){
   cout<<res[n][i]<<" ";
 }
 cout<<endl;
 return 0;
}
