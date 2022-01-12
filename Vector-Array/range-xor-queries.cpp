//link : https://cses.fi/problemset/task/1650

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n,m;
cin>>n>>m;
vector<int>arr(n+5);
vector<int>pref(n+5);
for(int i=1;i<=n;i++){
 cin>>arr[i];
 pref[i]=pref[i-1]^arr[i];
}
while(m--){
  int a,b;
  cin>>a>>b;
   cout<<(pref[b]^pref[a-1])<<endl;
}
 return 0;
}

