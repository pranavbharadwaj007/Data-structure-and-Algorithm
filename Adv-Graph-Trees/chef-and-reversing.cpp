// problem-link : codechef.com/problems/REVERSE


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>> adj[N];
vector<int>lev(N,INF);
int n,m;
int bfs(){
  deque<int>dq;
  dq.push_back(1);
  lev[1]=0;
  while(!dq.empty()){
  int cur_v=dq.front();
   dq.pop_front();
   for(auto &child:adj[cur_v]){
     int child_v=child.first;
     int wt=child.second;
     if(lev[cur_v]+wt<lev[child_v]){
      lev[child_v]=lev[cur_v]+wt;
      if(wt==1){
        dq.push_back(child_v);
      }else{
        dq.push_front(child_v);
      }
     }
   }
  }
  return lev[n] == INF ? -1 : lev[n];
}


int main() {
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    if(x==y)continue;
    adj[x].push_back(make_pair(y,0));
    adj[y].push_back(make_pair(x,1));
  }
 cout<<bfs()<<endl;

 return 0;
}
