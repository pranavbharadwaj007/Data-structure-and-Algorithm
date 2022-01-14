// link : https://cses.fi/problemset/task/2216/
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
int ans=0;
vector<int>freq(n+1,-1);
for(auto t:nums){
  if(freq[t-1]==-1){
    ans++;
  }
  freq[t]++;
}
cout<<ans<<endl;
 return 0;
}
