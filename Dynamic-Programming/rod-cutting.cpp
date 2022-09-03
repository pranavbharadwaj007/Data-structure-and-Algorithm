
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

int cutRod(int price[], int n) {
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=n;tar++){
                int notak=prev[tar];
                int tak=INT_MIN;
                int rodl=ind+1;
                if(rodl<=tar){
                    tak=price[ind]+curr[tar-rodl];
                }
                curr[tar]=max(tak,notak);
            }
            prev=curr;
        }
        return prev[n];
    }
