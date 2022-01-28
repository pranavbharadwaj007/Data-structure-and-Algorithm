// pow of a,b,c

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) (1e9+7)
#define int long long
int powfast(int a,int b,int m){
  if(b==0)return 1;
  int val=powfast(a,b/2,m);
  if(b & 1){
   return (((a*val)%m)*val)%m;
  }
  else{
return (val*val)%m;
  }
}
signed main() { 
int t;
cin>>t;
while(t--){
int a,b,c;
cin>>a>>b>>c;
int y=powfast(b,c,MOD-1);
int ans=powfast(a,y,MOD);
cout<<ans<<endl;
}
 return 0;
}
