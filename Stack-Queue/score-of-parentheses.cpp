class Solution {
public:
    int scoreOfParentheses(string s) {
       
        int cnt=0;
        stack<int>st;
        for(auto x:s){
            if(x=='('){
                 st.push(0); 
            }
            else{
                if(st.top()==0){
                    st.pop();
                    st.push(1);
                }else{
                    int sum=0;
                    while(st.top()!=0){
                        sum=sum+st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(sum*2);
                }
            }
          
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
