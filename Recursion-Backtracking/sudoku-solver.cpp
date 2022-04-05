
// Link : https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) 
                return false; 
            
            if(board[row][i] == c) 
                return false; 
            
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; 
        }
        return true;
    }
       bool solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char p='1';p<='9';p++){
                        if(isValid(board, i, j, p)){
                            board[i][j]=p;
                            if(solve(board)) return true;
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
    solve(board);
        
    }
};
