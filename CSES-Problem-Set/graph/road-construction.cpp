// link : https://cses.fi/problemset/task/1676/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int) (1e9+7);
const int N=1e5+10;
const int INF=1e18;
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
int Union(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    if(sizet[a]<sizet[b]){
      swap(a,b);
    }
    parent[b]=a;
    sizet[a]+=sizet[b];
  }
  return sizet[a];
}
signed main() {
cin>>n>>m;
int cnm=n;
int sz=1;
for(int i=1;i<=n;i++)make(i);
for(int i=0;i<m;i++){
  int a,b;
  cin>>a>>b;
  if(!(find(a)==find(b))){
  int curr_siz=Union(a,b);
  cnm--;
  sz=max(sz,curr_siz);
  }
  cout<<cnm<<" "<<sz<<endl;
}
 return 0;
}

