
// Link : https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        int par=kthGrammar(n-1,k/2+k%2);
        bool isOdd=(k%2==1);
        if(par){
            if(isOdd){
                return 1;
            }
            else{
                return 0;
            }
        }else{
            if(isOdd){
                return 0;
            }
            else{
                return 1;
            } 
        }
        
    }
};
