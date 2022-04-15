
// Link : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1/

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
