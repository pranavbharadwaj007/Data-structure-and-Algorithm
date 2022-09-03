
// Link : https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
    void dfs(long long num,int n,int k,vector<int>&res){
        if(n==0){
        res.push_back(num);
        return;
        }
        int last=num%10;
        if(last>=k)dfs((num*10)+last-k,n-1,k,res);
        if(k>0 && last+k<10)dfs((num*10)+last+k,n-1,k,res);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        if(n==1)res.push_back(0);
        for(int i=1;i<=9;i++){
            dfs(i,n-1,k,res);
        }
        return res;
    }
};
