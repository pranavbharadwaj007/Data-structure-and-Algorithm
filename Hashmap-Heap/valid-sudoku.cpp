// Link : https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]!='.'){
                    
                
                string sr="row"+to_string(i)+to_string(board[i][j]);
                string sc="colom"+to_string(j)+to_string(board[i][j]);
                
                if(st.count(sr)){
                    return false;
                }
                st.insert(sr);
                
                   if(st.count(sc)){
                    return false;
                }
                st.insert(sc);
                
            int box=(i/3)*3+j/3;
            string sb="box"+to_string(box)+to_string(board[i][j]);
            if(st.count(sb)){
                return false;
            }
                st.insert(sb);
                
                
                }
                
            }
            
        }
        return true;
    }
};
