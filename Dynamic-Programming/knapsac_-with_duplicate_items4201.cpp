
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

int knapSack(int n, int w, int val[], int wt[])
    {
        vector<int>curr(w+1,0), prev(w+1,0);
        for(int i=0;i<=w;i++){
            prev[i]=((int)i/wt[0])*val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=w;tar++){
                int notak=prev[tar];
                int tak=0;
                if(wt[ind]<=tar)tak=val[ind]+curr[tar-wt[ind]];
                curr[tar]=max(tak,notak);
            }
            prev=curr;
        }
        return prev[w];
    }
