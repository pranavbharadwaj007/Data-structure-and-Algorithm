class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int nottake=0+dp[ind-1][tar];
                int take=1e9;
                if(coins[ind]<=tar)take=1+dp[ind][tar-coins[ind]];
                
                dp[ind][tar]=min(take,nottake);
            }
            
        }
        if(dp[n-1][amount]==1e9)return -1;
        return dp[n-1][amount];
    }
};
