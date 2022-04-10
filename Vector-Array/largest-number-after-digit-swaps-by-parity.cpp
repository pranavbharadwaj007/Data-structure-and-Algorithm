
// https://leetcode.com/contest/weekly-contest-288/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
int maxi(int i,int j,bool iso,vector<int>&vec){
    int maxim=-1;
    int mini=-1;
    if(iso){
    for(int k=i;k<j;k++){
        if(vec[k]>maxim && vec[k]%2==1){
            maxim=vec[k];
            mini=k;
        }
    }
    }else{
        for(int k=i;k<j;k++){
        if(vec[k]>maxim && vec[k]%2==0){
            maxim=vec[k];
            mini=k;
        }
     }   
    }
  return mini;
}
    int largestInteger(int num) {
        int k=num;
        vector<int>vec;
        while(k){
            vec.push_back(k%10);
            k=k/10;
        }
        int mini=0;
        reverse(vec.begin(),vec.end());
        int n=vec.size();
        int pi=n;
        int tr=0;
        while(pi && tr<n){
                  if(n>tr){
          if(vec[tr]%2==1){
            mini= maxi(tr,n,true,vec);
            if(mini!=-1 && mini!=tr)
             {
            cout<<mini<<endl;
            swap(vec[tr],vec[mini]);
                pi--;
            }
        }else{
            mini= maxi(tr,n,false,vec);
            if(mini!=-1 && mini!=tr){
            cout<<mini<<endl;
            swap(vec[tr],vec[mini]);
                pi--;
            }
           } 
        }
        tr++;
        }
        long long sum=0;
        for(auto it:vec){
            sum*=10;
            sum+=it;
        }
        return sum;
    }
};
