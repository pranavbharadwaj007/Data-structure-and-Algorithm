// link : https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), column = grid[0].size(), count = 0;
        for(int i=0; i<row; ++i) {
            for(int j=0; j<column; ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]== '0' || grid[x][y] == '2'){
            return;
        }
        grid[x][y] = '2';
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }
};
