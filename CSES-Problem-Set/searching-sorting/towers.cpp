// link : https://cses.fi/problemset/task/1073/

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
multiset<int>mt;
for(auto a:nums){
  auto it=mt.upper_bound(a);
  if(it!=mt.end()){
    mt.erase(it);
    mt.insert(a);
  }
  else{
    mt.insert(a);
  }
}
cout<<mt.size()<<endl;
 return 0;
}
