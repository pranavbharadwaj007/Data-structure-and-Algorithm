// link : https://cses.fi/problemset/task/1713/

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) (1e9+7)
signed main() { 
int t;
cin>>t;
while(t--){
  int n;
  cin>>n;
 vector<int>vec;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
    vec.push_back(i);
    if((i*i)!=n){
      vec.push_back(n/i);
      }
    }
  }
  cout<<vec.size()<<endl;
}
 return 0;
}
