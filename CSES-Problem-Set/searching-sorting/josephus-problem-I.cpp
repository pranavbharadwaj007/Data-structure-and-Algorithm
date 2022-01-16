// link : https://cses.fi/problemset/task/2162/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n;
cin>>n;
deque<int>dq;
for(int i=1;i<=n;i++){
  dq.push_back(i);
}
while(!dq.empty()){
  int x=dq.front();
  dq.push_back(x);
  dq.pop_front();
  cout<<dq.front()<<" ";
  dq.pop_front();
}
cout<<endl;
 return 0;
}

