
// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vec(n,vector<int>(n,0));
        int rs=0;
        int cs=0;
        int re=n-1;
        int ce=n-1;
        int num=1;
        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce;i++){
                vec[rs][i]=num++;
            }
            rs++;
            for(int i=rs;i<=re;i++){
                vec[i][ce]=num++;
            }
            ce--;
            for(int i=ce;i>=cs;i--){
                vec[re][i]=num++;
            }
            re--;
            for(int i=re;i>=rs;i--){
                vec[i][cs]=num++;
            }
            cs++;
        }
        return vec;
    }
};
