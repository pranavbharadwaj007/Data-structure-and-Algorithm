
// Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>ph(26,0);
       vector<int>sh(26,0);
        if(s.length()<p.length())return {};
       for(int t=0;t<p.length();t++){
          ph[p[t]-'a']++;
          sh[s[t]-'a']++;
        }
   
        int i=0;
        
        int cnt=0;
        int k=p.length();
        int j=k-1;
        vector<int>ans;
        while(j<s.length()){
            if(ph==sh)ans.push_back(i);
            j++;
            if(j!=s.length())sh[s[j]-'a']++;
            sh[s[i]-'a']--;
            i++;
        }
        return ans;
    }
};
