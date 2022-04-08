// recursion
class Solution {
public:
    int fib(int n) {
        if(n<2){
            return n;
        }
        return fib(n-1)+fib(n-2);      
    }
};
// DP

class Solution {
public:
    int fib(int n) {
        vector <int> f(n+1);
        if(n == 0){   
            return 0;
        }
    f[0] = 0, f[1] = 1;
    for(int i = 2;i<=n;i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];   
    }
};



// space optimize

class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        int prev2=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
