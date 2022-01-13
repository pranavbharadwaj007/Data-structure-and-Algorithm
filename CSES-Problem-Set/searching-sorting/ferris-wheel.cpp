#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n,k;
cin>>n>>k;
vector<int>vec(n);
for(auto &it:vec){
  cin>>it;
}
sort(vec.begin(),vec.end());
int cnt=0;
int i=0,j=n-1;
while(i<=j){
 if(vec[i]+vec[j]<=k){
   i++;
   j--;
   cnt++;
 }
 else if(vec[j]<=k){
   j--;
   cnt++;
 }
 else if(vec[i]<=k){
   i++;
   cnt++;
 }
 else{
   i++;
   j--;
 }
}
cout<<cnt<<endl;
 return 0;
}
