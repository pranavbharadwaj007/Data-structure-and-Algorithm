//link : https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    const int N=1e5+10;
const int INF=1e9+10;
int dijkstra(int s,int n,vector<pair<int,int>>g[]){
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
    int ans=0;
    for(int i=1;i<=n;i++){
        if(distance[i]==INF)return -1;
        ans=max(ans,distance[i]);
    }
    return ans;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>g[N];
        for(auto it:times){
            g[it[0]].push_back({it[1],it[2]});
        }
        return dijkstra(k,n,g);
    }
};
