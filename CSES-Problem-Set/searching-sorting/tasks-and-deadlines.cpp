// link : https://cses.fi/problemset/result/3387896/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
vector<pair<int,int>>arr(n);
for(auto &a:arr){
  cin>>a.first>>a.second;
}
sort(arr.begin(),arr.end());
int time=0,rew=0;
for(auto t:arr){
  time+=t.first;
  rew+=(t.second-time);
 }
 cout<<rew<<endl;
 return 0;
}
