
// Link : https://leetcode.com/problems/sliding-window-maximum/

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int>res;
        list<int> lst;
        int i=0;
        int j=0;
        while(j<n){
          while(lst.size()>0 && lst.back()<arr[j]){
              lst.pop_back();
          }
          lst.push_back(arr[j]);
          if((j-i+1)<k)j++;
          else if((j-i+1)==k){
              res.push_back(lst.front());
              if(lst.front()==arr[i]){
                  lst.pop_front();
              }
               i++;
               j++;
          }
          
        }
        return res;
    }
