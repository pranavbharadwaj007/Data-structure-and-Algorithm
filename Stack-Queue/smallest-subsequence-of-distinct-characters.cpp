// Link : https://leetcode.com/problems/remove-duplicate-letters/ 
// Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        stack<char>st;
       vector<bool>cnt(26,false);
        vector<int>freq(26,0);
        for(auto x:s){
            freq[x-'a']++;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            freq[ch-'a']--;
            if(cnt[ch-'a'])continue;
            while(!st.empty() &&  st.top()>ch && freq[st.top()-'a'] ){
                cnt[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            cnt[ch-'a']=true;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
