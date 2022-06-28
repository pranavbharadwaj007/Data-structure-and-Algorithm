
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(auto &it:s){
            freq[it-'a']++;
        }
        unordered_set<int>st;
        int res=0;
        for(int i=0;i<26;i++){
            int currfreq=freq[i];
            while(currfreq>0){
                if(st.find(currfreq)!=st.end()){
                    currfreq--;
                    res++;
                }else{
                    break;
                }
            }
            if(currfreq!=0)st.insert(currfreq);
        }
        return res;
    }
};
