// link : https://cses.fi/problemset/task/1645/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define MOD 1000000007
int sumd(int _a){int res=0;while(_a){res=res+(_a%10);_a=_a/10;}return res;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int n;
cin>>n;
vector<int>arr(n);
for(auto &it:arr){
  cin>>it;
}
stack<int>st;
for(int i=0;i<n;i++){
  while(!st.empty() and arr[st.top()]>=arr[i]){
    st.pop();
  }
  if(st.empty()){
    cout<<0<<" ";
  }
  else{
    cout<<st.top()+1<<" ";
  }
    st.push(i);
}
cout<<endl;
 return 0;
}
