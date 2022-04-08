
// Link : https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    void dfs(vector<vector<int>>&mat,int r,int c,int prev, vector<vector<int>>&ocean){
        if(r<0 || c<0 || r>=mat.size() || c>=mat[0].size()){
            return;
        }
        if(mat[r][c]<prev){
            return;
        }
        if(ocean[r][c]==-1){
            return;
        }
        ocean[r][c]=-1;
        dfs(mat,r+1,c,mat[r][c],ocean);
        dfs(mat,r,c+1,mat[r][c],ocean);
        dfs(mat,r-1,c,mat[r][c],ocean);
        dfs(mat,r,c-1,mat[r][c],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        vector<vector<int>>ans;
        if(mat.size()==0)return ans;
       
        vector<vector<int>>atl(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>pac(mat.size(),vector<int>(mat[0].size(),0));
        
        for(int col=0;col<mat[0].size();col++){
           dfs(mat,0,col,INT_MIN,pac);
           dfs(mat,mat.size()-1,col,INT_MIN,atl);
        }
        for(int row=0;row<mat.size();row++){
           dfs(mat,row,0,INT_MIN,pac);
           dfs(mat,row,mat[0].size()-1,INT_MIN,atl);
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(pac[i][j]==-1 && pac[i][j]==atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
