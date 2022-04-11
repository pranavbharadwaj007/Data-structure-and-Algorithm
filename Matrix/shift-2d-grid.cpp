
// Link : https://leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    void reverse(vector<int>&vec,int l,int r){
        while(l<r){
            swap(vec[l++],vec[r--]);
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>vec;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int pi=n*m;
        k=k%(n*m);
        reverse(vec,0,pi-k-1);
        reverse(vec,pi-k,pi-1);
        reverse(vec,0,pi-1);
        int p=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=vec[p++];
            }
        }
        return grid;
    }
};
