// link : https://cses.fi/problemset/task/1672/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) (1e18)
const int N=1e5+10;
signed main() {
int n,m,q;
cin>>n>>m>>q;
int arr[n+1][n+1];
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    arr[i][j]=INF;
    if(i==j)arr[i][j]=0;
  }
}
for(int i=0;i<m;i++){
  int a,b,w;
  cin>>a>>b>>w;
  arr[a][b]=min(arr[a][b],w);
  arr[b][a]=min(arr[b][a],w);
}
for(int k=1;k<=n;k++){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    }
  }
}
while(q--){
  int t,r;
  cin>>t>>r;
  if(arr[t][r]==INF)cout<<-1<<endl;
  else cout<<arr[t][r]<<endl;
}
 return 0;
}
