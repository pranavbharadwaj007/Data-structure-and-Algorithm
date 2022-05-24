
// Link : https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len=i-st.top();
                    maxi=max(maxi,len);                   
                }
            }
        }
        return maxi;
    }
};
