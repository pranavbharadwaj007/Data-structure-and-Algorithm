#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxi = 1e5+10;
const int INF=1e9+10;
int vis[8][8];
int lev[8][8];
int getX(string s){
 return s[0]-'a';
}
int getY(string s){
  return s[1]-'1';
}
vector<pair<int,int>> mov={
  {-1,2},{1,2},
  {-1,-2},{1,-2},
  {2,-1},{2,1},
  {-2,-1},{-2,1}

};
bool isValid(int cx,int cy){
  if(cx>=0 && cy>=0 && cx<8 && cy<8) return true;
  return false;
}
int bfs(string source,string destination){
  int sx=getX(source);
  int sy=getY(source);
  int dx=getX(destination);
  int dy=getY(destination);
  queue<pair<int,int>>q;
  q.push({sx,sy});
  vis[sx][sy]=1;
  lev[sx][sy]=0;
  while(!q.empty()){
      pair<int,int> cv=q.front();
      int x=cv.first,y=cv.second;
      q.pop();
      for(auto mo:mov){
        int cx=mo.first+x;
        int cy=mo.second+y;
        if(!isValid(cx,cy))continue;
        if(!vis[cx][cy]){
          q.push({cx,cy});
          lev[cx][cy]=lev[x][y]+1;
          vis[cx][cy]=1;
        }
      }
      if(lev[dx][dy]!=INF){
        break;
      }
  }
  return lev[dx][dy];
}
void reset(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      vis[i][j]=0;
      lev[i][j]=INF;
    }
  }
}
int main() {
int n;
cin>>n;
while(n--){
  reset();
  string s1,s2;
  cin>>s1>>s2;
  cout<<bfs(s1,s2)<<endl;

}
 return 0;
}
