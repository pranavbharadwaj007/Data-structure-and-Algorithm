
// Link : https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string res1="";
        string res2="";
        
        
        for(int i=0;i<S.length();i++){
         if(S[i]>='a'&&S[i]<='z'){
             res1+=S[i];
         }    
            else if(!res1.empty())
                res1.pop_back();
        }
           for(int i=0;i<T.length();i++){
         if(T[i]>='a'&&T[i]<='z'){
             res2+=T[i];
         }    
            else if(!res2.empty())
                res2.pop_back();
        }
        return res1==res2;
    }
};
