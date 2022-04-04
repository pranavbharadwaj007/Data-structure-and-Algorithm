
// Link : https://leetcode.com/contest/weekly-contest-287/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    long long maxi(long long x,long long y){
        if(x>=y)return x;
        return y;
    }
    bool isp(vector<int>&c,long long mid,long long k){
        long long cnt=0;
        for(auto it:c){
            cnt+=(it/mid);
        }
        if(cnt>=k)return true;
        return false;
    }
    int maximumCandies(vector<int>& c, long long k) {
       long long sum=0;
        for(int i=0;i<c.size();i++){
            sum+=c[i];
        }
        long long hi=sum/k;
        hi++;
        long long lo=0;
        long long ans=0;
        while(lo<hi){
            long long mid=(hi+lo)/2;
            if(mid==0)return 0;
            if(isp(c,mid,k)){
                ans=maxi(ans,mid);
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return ans;
    }
};
