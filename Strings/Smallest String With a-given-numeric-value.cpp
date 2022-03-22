// Link : https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        k=k-n;
        // string 
        // initially  aaaaaaa n times
        // we need z count at the end (z/25) and a separator w at between z and a calculated k%25;
        int zc=k/25;
        int wc=k%25;
        int i=n-1;
        while(zc-->0){
            s[i--]='z';
        }
       if(wc>0){
           s[i]=(char)('a'+wc);
       }
        return s;
    }
};
