// link : https://cses.fi/problemset/task/1632/

#include<bits/stdc++.h>
#define int long long 
using namespace std;
#define MOD 1000000007

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int n,k;
cin>>n>>k;
vector<pair<int,int>>vec(n);
for(auto &it:vec){
  cin>>it.second>>it.first;
}
sort(vec.begin(),vec.end());
multiset<int>mp;
int cnt=0;
for(auto it:vec){
  auto up=mp.upper_bound(it.second);
  if(up!=mp.begin()){
    up--;
    mp.erase(up);
  }
  if(size(mp)<k){
    mp.insert(it.first);
    cnt++;
  }
}
cout<<cnt<<endl;

 return 0;
}
