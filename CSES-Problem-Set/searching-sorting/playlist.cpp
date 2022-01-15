// link : https://cses.fi/problemset/task/1141/

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
int p1=0,p2=0;
int ans=0;
set<int>st;
while(p2<n){
if(st.find(nums[p2])!=st.end()){
  while(nums[p1]!=nums[p2]){
    st.erase(nums[p1]);
    p1++;
  }
  p1++;
 }
   else{
    st.insert(nums[p2]);
  }
  p2++;
  ans=max(ans,p2-p1);
}
cout<<ans<<endl;
 return 0;
}
