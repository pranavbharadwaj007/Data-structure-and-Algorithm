
// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// MEMOIZ

int fun(int n,vector<int> &h,vector<int> &dp){
	if(n==0){
	
		return 0;
	}
	if(dp[n]!=-1)return dp[n];
	int l=fun(n-1,h,dp)+abs(h[n]-h[n-1]);
	int r=1e7;
	if(n>1){
		r=fun(n-2,h,dp)+abs(h[n]-h[n-2]);
	}
	return dp[n]=min(l,r);
}

// TABULATION

int frogJump(int n, vector<int> &heights)
{
   int res;
	vector<int>dp(n,0);
	for(int i=1;i<n;i++){
		int l=dp[i-1]+abs(heights[i]-heights[i-1]);
		int r=1e7;
	    if(n>1){
			r=dp[i-2]+abs(heights[i]-heights[i-2]);		
	    }
		dp[i]=min(l,r);
	}
    return dp[n-1];
}

// SPACE OPTIMIZATION

int frogJump(int n, vector<int> &h)
{
    int prev2=0;
	  int prev1=0;
	  for(int i=1;i<n;i++){
		int l=prev1+abs(h[i]-h[i-1]);
		int r=1e7;
		if(i>1)
		r=prev2+abs(h[i]-h[i-2]);
		 int curr=min(l,r);
		prev2=prev1;
		prev1=curr;
	}
	return prev1;
}
