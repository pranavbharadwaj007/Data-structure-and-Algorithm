// link : https://cses.fi/problemset/task/1620/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n,t;
cin>>n>>t;
vector<int>arr(n);
for(auto &it:arr)cin>>it;
int lo=0,hi=1e18;
int res=0;
while(lo<=hi){
  int mid=(hi+lo)/2;
  int cnt=0;
  for(auto &it:arr){
    cnt+=(min(mid/it,t));
  }
  if(cnt>=t){
    res=mid;
    hi=mid-1;
  }
  else{
    lo=mid+1;
  }
}
cout<<res<<endl;
 return 0;
}
