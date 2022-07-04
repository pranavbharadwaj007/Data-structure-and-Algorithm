
// Link : https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res=0;
        int n=ratings.size();
        
        vector<int>rig(n,1);
        vector<int>lef(n,1);
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])lef[i]=lef[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])rig[i]=rig[i+1]+1;
        }
        for(int i=0;i<n;i++){
            res+=(max(lef[i],rig[i]));
        }
        return res;
    }
};
