
// Link : https://leetcode.com/problems/letter-case-permutation/


class Solution {
public:
    void lcp(int ind,string s,vector<string>&ans,string res){
        if(ind>=s.length()){
            ans.push_back(res);
            return;
        }
        int ch = s[ind];
        if(ch>=48 && ch<=57){
            res.push_back(s[ind]);
            lcp(ind+1,s,ans,res);
        }
        else{
            res.push_back(tolower(s[ind]));
            lcp(ind+1,s,ans,res);
            res.pop_back();
            
           res.push_back(toupper(s[ind]));
            lcp(ind+1,s,ans,res);
           res.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string res="";
        lcp(0,s,ans,res);
        return ans;
    }
};
