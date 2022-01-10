#include<bits/stdc++.h>
using namespace std;
 #define int long long
#define mod (int) (1e9+7);
const int N=1e5+10;
int parent[N];
int sizet[N];
int n,m;
void make(int v){
 parent[v]=v;
 sizet[v]=1;
}
int find(int v){
 if(parent[v]==v)return parent[v];
  return parent[v]=find(parent[v]);
}
void Union(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    if(sizet[a]<sizet[b]){
      swap(a,b);
    }
    parent[b]=a;
    sizet[a]+=sizet[b];
  }
}
signed main() {
cin>>n>>m;
vector<pair<int,pair<int,int>>>vec;
for(int i=0;i<m;i++){
 int u,v,w;
 cin>>u>>v>>w;
 vec.push_back({w,{u,v}});
}
int ans=0;
int cnt=0;
for(int i=1;i<=n;i++)make(i);
sort(vec.begin(),vec.end());
for(auto &it:vec){
  int wt=it.first;
  int x=it.second.first;
  int y=it.second.second;
  if(find(x)==find(y))continue;
  Union(x,y);
  cnt++;
 ans+=wt;
}
if(cnt==n-1){
cout<<ans<<endl;
}
else{
  cout<<"IMPOSSIBLE"<<endl;
}

 return 0;
}

