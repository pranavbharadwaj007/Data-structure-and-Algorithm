
// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i= -1;
        int j= -1;
        int res=0;
        while(true){
            bool f1=false,f2=false;
            while(i<(int)s.size()-1){
                f1=true;
                i++;
                char ch=s[i];
                if(mp.find(ch)!=mp.end()){
                    mp[ch]++;
                }else{
                    mp[ch]=1;
                }
                if(mp[ch]==2)break;
                else{
                  res=max(res,i-j);  
                }
                
            }
            while(j<i){
                   f2=true;
                j++;
                char ch=s[j];
                mp[ch]--;
                if(mp[ch]==1)break;
                
             
            }
            if(!f1 && !f2)break;
        }
        return res;
    }
};
