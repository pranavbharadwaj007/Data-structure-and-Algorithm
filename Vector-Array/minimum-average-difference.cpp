
// Link : https://leetcode.com/contest/biweekly-contest-77/problems/minimum-average-difference/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>pref,suf;
        long long sum=0;
        for(auto it:nums){
            sum+=it;
            pref.push_back(sum);
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
           suf.push_back(sum);
        }
        reverse(suf.begin(),suf.end());
        suf.push_back(0);
        long long res=1e17;
        int resi=0;
        int n=nums.size();
        int p=1; 
        for(int i=0;i<nums.size();i++){
            if((n-p)==0){
            long long diff=abs(((pref[i])/(i+1))-(0));
                p++;
            if(diff<res){
                res=diff;
                resi=i;
            }  
            }else{
            long long diff=abs(((pref[i])/(i+1))-((suf[p])/(n-p)));
                p++;
            if(diff<res){
                res=diff;
                resi=i;
            }  
            }
        }
        return resi;
    }
};
