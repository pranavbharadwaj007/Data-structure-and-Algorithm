// link : https://leetcode.com/problems/01-matrix/

class Solution {
public:
bool isValid(int cx,int cy,int r,int c){
  if(cx>=0 && cy>=0 && cx<r && cy<c) return true;
  return false;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
         vector<pair<int,int>> mov={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)q.push({i,j});
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while(q.size()>0){
            auto it=q.front();
            q.pop();
            for(auto pt:mov){
                int cx=it.first+pt.first;
                int cy=it.second+pt.second;
                if(isValid(cx,cy,mat.size(),mat[0].size()) && mat[cx][cy]<0){
                    q.push({cx,cy});
                    mat[cx][cy]=mat[it.first][it.second]+1;
                }
                
            }
        }
        return mat;
    }
};
