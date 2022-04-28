
// Link : https://atcoder.jp/contests/dp/tasks/dp_c

// Memo

int fun(int day,int last,vector<vector<int>> &points, vector<vector<int>> &dp){
	if(day==0){
		int maxi=0;
		for(int i=0;i<3;i++){
			if(i!=last){
				maxi=max(maxi,points[0][i]);
			}
		}
		return maxi;
	}
	if(dp[day][last]!=-1)return dp[day][last];
	int maxim=0;
	for(int k=0;k<3;k++){
		if(k!=last){
			int point=points[day][k]+fun(day-1,k,points,dp);
			maxim=max(maxim,point);
		}
	}
	return dp[day][last]=maxim;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
	  vector<vector<int>>dp(n,vector<int>(4,-1));
    return fun(n-1,3,points,dp);
}

// Tabulation


int ninjaTraining(int n, vector<vector<int>> &points)
{
	vector<vector<int>>dp(n,vector<int>(4,0));
	dp[0][0]=max(points[0][1],points[0][2]);
	dp[0][1]=max(points[0][0],points[0][2]);
	dp[0][2]=max(points[0][1],points[0][0]);
	dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
	
	for(int day=1;day<n;day++){
		for(int last=0;last<4;last++){
			dp[day][last]=0;
			for(int task=0;task<3;task++){
				if(task!=last){
					int point=points[day][task]+dp[day-1][task];
					dp[day][last]=max(dp[day][last],point);
				}
			}
		}
	}
	return dp[n-1][3];
}
