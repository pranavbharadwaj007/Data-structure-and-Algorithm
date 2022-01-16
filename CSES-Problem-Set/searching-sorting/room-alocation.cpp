// link : https://cses.fi/problemset/task/1164/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
vector<pair<int,pair<int,int>>>vec;
// vec stores {point (time of event) ,type(in/out),index (value of i) }
for(int i=1;i<=n;i++){
 int start,end;
 cin>>start>>end;
 vec.push_back({start,{0,i}});
 vec.push_back({end,{1,i}});
}
sort(vec.begin(),vec.end());
set<int>avail;
for(int i=1;i<=n;i++){
  avail.insert(i);
}
vector<int>res(n);
for(auto it:vec){
  if(it.second.first==0){
      res[it.second.second]=*avail.begin();
      avail.erase(avail.begin());
  }
  else{
    avail.insert( res[it.second.second]);
  }
}
cout<<*max_element(res.begin(),res.end())<<endl;
for(int i=1;i<=n;i++){
  cout<<res[i]<<" ";
}
 return 0;
}
