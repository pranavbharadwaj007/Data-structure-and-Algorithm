// Link: https://leetcode.com/problems/coloring-a-border

class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int row, int col, int color)
    {
        grid[row][col]=-color;
        int count=0;
        int x[]={0,1,0,-1};
        int y[]={1,0,-1,0};
        for(int i=0;i<4;i++)
        {
            int r=row+x[i];
            int c=col+y[i];
            if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||abs(grid[r][c])!=color)
            {
                continue;
            }
            count++;
            if(grid[r][c]==color)
            {
                dfs(grid,r,c,color);
            }
        }
        if(count==4)
        {
            grid[row][col]=color;
            
        }   
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
    {
        dfs(grid,row,col,grid[row][col]);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                {
                    grid[i][j]=color;
                }
            }
        }
        
        return grid;
    }
};
