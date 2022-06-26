
// Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        int i=0;
        int j=n-k;
        int sum=0;
        for(int l=j;l<n;l++){
            sum+=cp[l];
        }
        int ans=sum;
        while(j<n){
            sum+=(cp[i]-cp[j]);
            ans=max(ans,sum);
            i++;
            j++;
        }
        return ans;
    }
};
