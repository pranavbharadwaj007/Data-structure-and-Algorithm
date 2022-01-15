// link : https://cses.fi/problemset/task/1163/

#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)

signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
int len,q;
cin>>len>>q;
multiset<int>lens;
lens.insert(len);

set<pair<int,int>>ranges ; // store (end,start) easy to do lower bound in pair 

as we need to find equal or greater element of ranges
ranges.insert({len,0});
while(q--){
  int x;
  cin>>x;
  auto lb=ranges.lower_bound({x,-1});
  int start=(*lb).second;
  int end=(*lb).first;
  int diff=end-start;
  
  ranges.erase(lb);
  ranges.insert({x,start});
  ranges.insert({end,x});

  lens.erase(lens.find(diff));
  lens.insert(x-start);
  lens.insert(end-x);

  cout<<*(lens.rbegin())<<" ";//prints greater element in mset.

}
 return 0;
}
