// Link : https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
        void dfs(vector<vector<int>>& board,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]==1){
            return;

        }

        board[i][j]=1;
        dfs(board,i-1,j,n,m);
        dfs(board,i+1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);

    }
    int closedIsland(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
            for(int i=0;i<n;i++){
            int j=0;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
            j=m-1;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
        }
        for(int j=0;j<m;j++){
            int i=0;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
            i=n-1;
            if(board[i][j]==0){
                dfs(board,i,j,n,m);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    cnt++;
                    dfs(board,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};
