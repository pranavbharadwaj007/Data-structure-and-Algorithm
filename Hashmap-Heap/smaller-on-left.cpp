// Link : https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1

vector<int> Smallestonleft(int arr[], int n)
{
   set<int>st;
   vector<int>vec;
   for(int i=0;i<n;i++){
       int x=arr[i];
       auto it=st.lower_bound(x);
       if(it==st.begin()){
           vec.push_back(-1);
       }else{
           --it;
           vec.push_back(*it);
       }
       st.insert(x);
   }
   return vec;
}
