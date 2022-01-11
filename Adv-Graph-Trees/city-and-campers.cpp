// link : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int) (1e9+7);
const int N=1e5+10;
const int INF=1e18;
int parent[N];
int sizet[N];
multiset<int>sizes;
int n,m;
void make(int v){
 parent[v]=v;
 sizet[v]=1;
 sizes.insert(1);
}
int find(int v){
 if(parent[v]==v)return parent[v];
  return parent[v]=find(parent[v]);
}
void merge(int a,int b){
  sizes.erase(sizes.find(sizet[a]));
  sizes.erase(sizes.find(sizet[b]));
  sizes.insert(sizet[a]+sizet[b]);
}
void Union(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    if(sizet[a]<sizet[b]){
      swap(a,b);
    }
    parent[b]=a;
    merge(a,b);
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
    if(sizes.size()==1){
    cout<<0<<endl;
  }
  else{
    int mn=*(sizes.begin());
    int mx= *(--sizes.end());
    cout<<mx-mn<<endl;
  }
}

 return 0;
}

