#include<bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
#define int long long
signed main() {
int n,m,k;
cin>>n>>m>>k;
vector<int>vec(n);
vector<int>arr(m);
for(auto &it:vec){
  cin>>it;
}
for(auto &it:arr){
  cin>>it;
}
sort(vec.begin(),vec.end());
sort(arr.begin(),arr.end());
int p1=0,p2=0,cnt=0;
while(p1<n && p2<m){
 if((arr[p2]<= vec[p1]+k) && (arr[p2]>=vec[p1]-k)){
   cnt++;
   p1++;
   p2++;
 }
 else if(arr[p2]< (vec[p1]-k)){
   p2++;
 }
 else{
   p1++;
 }
}
cout<<cnt<<endl;
 return 0;
}
 
 
