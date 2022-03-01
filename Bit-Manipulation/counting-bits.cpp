// Link : https://leetcode.com/problems/counting-bits/

// Naive approach

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>cb;
            for(int i=0;i<=num;i++){
                int cnt=0;
                int n=i;
                while(n){
                    cnt++;
                    n=n&(n-1);
                }
                cb.push_back(cnt);
                    
            }
        
        return cb;
    }
};

// optimized dp O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        res[0]=0;
        for(int i=1;i<=n;i++){
            res[i]+=(res[i/2]+(i&1)); 
        }
        return res;
    }
};
