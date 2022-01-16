// link : https://cses.fi/problemset/task/1631/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
vector<int>arr(n);
for(auto &a:arr){
  cin>>a;
}
int maxi=INT_MIN,sum=0;
for(auto a:arr){
sum+=a;
maxi=max(maxi,a);
}
cout<<max(sum,2*maxi)<<endl;
 return 0;
}
