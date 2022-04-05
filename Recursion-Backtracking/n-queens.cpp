
// Link : https://leetcode.com/problems/n-queens/

class Solution {
public:
    void nqu(int col,vector<string>& board,vector<vector<string>> &ans,vector<int>& leftrow,vector<int>& updiag,vector<int>& lowdiag,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowdiag[row+col]==0 && updiag[(n-1)+col-row]==0){
                leftrow[row]=1;
                lowdiag[row+col]=1;
                updiag[(n-1)+col-row]=1;
                board[row][col]='Q';
                nqu(col+1,board,ans,leftrow,updiag,lowdiag,n);
                leftrow[row]=0;
                lowdiag[row+col]=0;
                updiag[(n-1)+col-row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>updiag(2*n-1,0);
        vector<int>lowdiag(2*n-1,0);
        nqu(0,board,ans,leftrow,updiag,lowdiag,n);
        return ans;
    }
};
