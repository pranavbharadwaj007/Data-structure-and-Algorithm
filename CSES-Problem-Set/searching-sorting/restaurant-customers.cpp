// link : https://cses.fi/problemset/task/1619/
#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
vector<pair<int,int>>res;
for(int i=0;i<n;i++){
 int a,b;
 cin>>a>>b;
 res.push_back({a,0});
 res.push_back({b,1});
}
sort(res.begin(),res.end());
int ans=0,maxi=0;
for(auto e:res){
  if(e.second==0){
    ans++;
  }
  else{
    ans--;
  }
  maxi=max(maxi,ans);
}
cout<<maxi<<endl;
 return 0;
}
