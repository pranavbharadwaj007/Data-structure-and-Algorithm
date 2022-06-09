
// Link : https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)dp[0][i]=mat[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u=mat[i][j]+dp[i-1][j];
                int ld=mat[i][j];
                if(j-1>=0)ld+=(dp[i-1][j-1]);
                else ld+=(1e7);
                int rd=mat[i][j];
                if(j+1<m)rd+=dp[i-1][j+1];
                else rd+=(1e7);
                dp[i][j]=min(u,min(ld,rd));
            }
        }
        int res=1e8;
        for(int i=0;i<m;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
    }
};
