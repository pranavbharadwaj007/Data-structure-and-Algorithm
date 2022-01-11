// link : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
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
for(int i=1;i<=n;i++)make(i);
for(int i=0;i<m;i++){
  int a,b;
  cin>>a>>b;
  if(!(find(a)==find(b))){
  Union(a,b);
 
  }
}
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(find(i)==i){
      cnt++;
    }
  }
  cout<<cnt<<endl;
 return 0;
}
