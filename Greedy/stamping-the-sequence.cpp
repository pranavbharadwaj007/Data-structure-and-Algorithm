
// Link : https://leetcode.com/problems/stamping-the-sequence/

class Solution {
public:
    bool isMatch(string &s, string &stamp, int i){
        for(int j=0; j<stamp.size(); j++)
            if(s[i+j]!='?' and s[i+j]!=stamp[j])
                return false;
        return true;
    }
    
    void replace(string &s, int i, int &len_st, int &ques){
        for(int j=0; j<len_st; j++){
            if(s[i+j]!='?'){
                ques++;
                s[i+j] = '?';
            }
        }
    }
    
    vector<int> movesToStamp(string stamp, string t) {
        int ques = 0, len_st = stamp.size(), len_t = t.size();
        vector<int> vis(len_t), ans;
        
        while(ques < len_t){
            bool did_stamp = false;
            for(int i=0; i<=len_t-len_st; i++){
                if(!vis[i] and isMatch(t, stamp, i)){
                    ans.push_back(i);
                    vis[i] = did_stamp = 1;
                    replace(t, i, len_st, ques);
                }
            }
            if(!did_stamp) return {};
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
