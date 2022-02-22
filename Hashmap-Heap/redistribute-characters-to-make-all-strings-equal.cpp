class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(auto c:words){
            for(auto x:c){
                mp[x]++;
            }
        }
        int n=words.size();
        for(auto it:mp){
            if(it.second%n!=0)return false;
        }
        return true;
    }
};
