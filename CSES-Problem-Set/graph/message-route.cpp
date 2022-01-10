// link : https://cses.fi/problemset/task/1667/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m;
const int maxi=1e5+10;
vector<int>g[maxi];
int vis[maxi];
void bfs(){
  vis[1]=-1;
  queue<int>q;
  q.push(1);
  while(!q.empty()){
  auto curr=q.front();
  q.pop();
  for(auto it:g[curr]){
     if(!vis[it]){
       vis[it]=curr;
       q.push(it);
     }
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
bfs();
vector<int>res;
int tem=n;
while(vis[tem] && vis[tem]!=-1){
  res.push_back(vis[tem]);
  tem=vis[tem];
}
if(size(res)){
reverse(res.begin(),res.end());
res.push_back(n);
cout<<size(res)<<endl;
for(auto x:res){
  cout<<x<<" ";
}
cout<<endl;
}
else{
  cout<<"IMPOSSIBLE"<<endl;
}
cout<<endl;
 return 0;
}
