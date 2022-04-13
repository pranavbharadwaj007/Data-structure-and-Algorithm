
// Link : https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       vector<int>vec;
        int rs=0;
        int cs=0;
        int re=n-1;
        int ce=m-1;
        
        while(rs<=re && cs<=ce){
          for(int i=cs;i<=ce;i++){
                vec.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i=rs;i<=re;i++){
               vec.push_back(matrix[i][ce]);
            }
            ce--;
            if(rs<=re){
            for(int i=ce;i>=cs;i--){
                vec.push_back(matrix[re][i]);
            }
            re--; 
            }
            if(cs<=ce){
            for(int i=re;i>=rs;i--){
                vec.push_back(matrix[i][cs]);
            }
            cs++;  
            }
     
        }
        return vec;
    }
};
