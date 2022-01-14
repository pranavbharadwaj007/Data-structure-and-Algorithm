// link : https://cses.fi/problemset/task/2183/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
vector<int> nums(n);
for(auto &N:nums){
  cin>>N;
}
int ans=1;
sort(nums.begin(),nums.end());
for(auto x:nums){
  if(ans<x){
    break;
  }
  ans+=x;
}
cout<<ans<<endl;
 return 0;
}
