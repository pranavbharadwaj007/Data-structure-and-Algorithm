
// Link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto c:s){
            if(!st.empty() && st.top().first==c){
                st.top().second++;
            }else{
                st.push({c,1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            auto it=st.top();
            while(it.second-->0){
                 res+=it.first;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
