// Anagram 
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        for(auto x:t){
            mp[x]--;
        }
        for(auto it:mp){
            if(it.second!=0)return false;
        }
        return true;
    }
};
