
// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    int count(int i,int j,vector<vector<int>>&board)
     {
         int count=0;
         vector<vector<int>> direction={{0,-1},{0,1},{1,0},{1,-1},{1,1},{-1,-1},{-1,1},{-1,0}};
         for(auto  dir:direction)
         {
             int x=i+dir[0];
             int y=j+dir[1];
             if(x>=0 && y>=0 && x<board.size() && y<board[0].size())
             {
                 count+=board[x][y];
             }
         }
         return count;
     }
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int> > output( board.size() , vector<int> (board[0].size(), 0));  
        for(int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[i].size();j++)
            {
               int neighbour = count(i,j,board);
                //Rule 1
                if(board[i][j]==1 && neighbour<2)
                    output[i][j]=0;
                //Rule 2
                else if(board[i][j]==1 && (neighbour==2 || neighbour==3))
                    output[i][j]=1;
                //Rule 3
                 else if(board[i][j]==1 && neighbour>3)
                    output[i][j]=0;
                //Rule 4
                 else if(board[i][j]==0 && neighbour==3)
                    output[i][j]=1;
            }         
                    
        }
        for(int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[i].size();j++)
            {
                board[i][j]=output[i][j];
            }
        }

    }
};
