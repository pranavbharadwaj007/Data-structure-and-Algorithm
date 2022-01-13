// link : https://cses.fi/problemset/task/1091/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n,m;
cin>>n>>m;
vector<int>vec(n);
for(auto &V:vec)cin>>V;
multiset<int>mt;
for(auto t:vec){
  mt.insert(t);
}

vector<int>arr(m);
for(auto &it:arr){
  cin>>it;
}
vector<int>res(m,-1);
for(int i=0;i<m;i++){
  auto it=mt.lower_bound(arr[i]);
  if( (it!=mt.end()) and (*it==arr[i])){
    res[i]=*it;
    mt.erase(it);
  }
  else if(it!=mt.begin()){
    it--;
     res[i]=*it;
    mt.erase(it);
  }
 
}
for(auto t:res){
  cout<<t<<endl;
}

 return 0;
}
