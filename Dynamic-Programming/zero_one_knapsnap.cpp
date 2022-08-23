
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

