// link : https://www.codingninjas.com/codestudio/problems/maximum-value-of-f-x-ii_2245751?source=youtube&campaign=Strivercontest6thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Strivercontest6thfeb&leftPanelTab=0

int f(int i,int j,string &s,string &g, int n,int m,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cmp=0;
    if(s[i]==g[j])cmp=1+f(i-1,j-1,s,g,n,m,dp);
    int ncmp=max(f(i-1,j,s,g,n,m,dp),f(i,j-1,s,g,n,m,dp));
    return dp[i][j] = max(cmp,ncmp);
    
}

int maxFXII(string &s, string &t, int n, int m){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return 2 * f(n-1,m-1,s,t,n,m,dp);
}
