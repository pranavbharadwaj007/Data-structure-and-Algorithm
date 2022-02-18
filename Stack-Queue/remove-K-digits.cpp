// link : https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int p=k;
       stack<char>st;
        for(auto it:num){
            while(!st.empty() && k>0 && st.top()>it){
                st.pop();
                k--;
            }
            if(!st.empty() || it!='0'){
                st.push(it);
            }
        }
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty())return "0";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
