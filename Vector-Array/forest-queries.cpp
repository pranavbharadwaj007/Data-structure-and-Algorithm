// link : https://cses.fi/problemset/task/1652/

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n,m;
cin>>n>>m;
int mat[n+5][n+5],pref[n+5][n+5];
memset(mat,0,sizeof mat);
memset(pref,0,sizeof pref);
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    char x;
    cin>>x;
    if(x=='*'){
      mat[i][j]=1;
    }
    // update col matrix
    pref[i][j]=pref[i][j-1]+mat[i][j];
  }
}
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    pref[i][j]=pref[i-1][j]+pref[i][j];
  }
}
while(m--){
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  cout<<pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1]<<endl;
}
 return 0;
}

