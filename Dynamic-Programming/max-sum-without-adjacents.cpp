
// Link : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1/

// MEMO

class Solution{
public:	
	int solve(int ind,int *arr,vector<int>&dp){
	    if(ind==0)return arr[ind];
	    if(ind<0)return 0;
	    if(dp[ind]!=-1)return dp[ind];
	    int pick=arr[ind]+solve(ind-2,arr,dp);
	    int notpick=0+solve(ind-1,arr,dp);
	    return dp[ind]=max(pick,notpick);
	}
	int findMaxSum(int *arr, int n) {
	   vector<int>dp(n,-1);
	   
	   return solve(n-1,arr,dp);
	}
};

// TABULATION

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	   vector<int>dp(n,-1);
	   dp[0]=arr[0];
	   for(int i=1;i<n;i++){
	       int pick=arr[i];if(i>1)pick+=dp[i-2];
	       int notpick=0+dp[i-1];
	       dp[i]=max(pick,notpick);
	   }
	   return dp[n-1];
	}
};

// SPACE OPTIMIZATION

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
       int prev1=arr[0];
       int prev2=0;
	   for(int i=1;i<n;i++){
	       int pick=arr[i];if(i>1)pick+=prev2;
	       int notpick=0+prev1;
	       int curr=max(pick,notpick);
	       prev2=prev1;
	       prev1=curr;
	   }
	   return prev1;
	}
};
