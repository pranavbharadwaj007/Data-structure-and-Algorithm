class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int rows,int cols,int source){
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        else if(image[sr][sc]!=source){
            return;
        }
        image[sr][sc]=newColor;
         dfs(image,sr-1,sc,newColor,rows,cols,source);
         dfs(image,sr+1,sc,newColor,rows,cols,source);
         dfs(image,sr,sc-1,newColor,rows,cols,source);
         dfs(image,sr,sc+1,newColor,rows,cols,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc]){
            return image;
        }
        int rows=image.size();
        int cols=image[0].size();
        int source=image[sr][sc];
        dfs(image,sr,sc,newColor,rows,cols,source);
        return image;
    }
};
