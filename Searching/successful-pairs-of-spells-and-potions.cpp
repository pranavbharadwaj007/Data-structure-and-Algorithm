
// Link : https://leetcode.com/contest/biweekly-contest-80/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>res;
        for(auto it:spells){
            int i=0;
            int j=potions.size()-1;
            int tem=j+1;
            int ans=-1;
            while(i<=j){
                int mid=(i+j)/2;
                long long res=(long long)it*potions[mid];
                if(res>=success){
                    j=mid-1;
                    ans=mid;
                }else{
                    i=mid+1;
                }
            }
           // cout<<ans<<endl;
            if(ans==-1)res.push_back(0);
            else res.push_back(tem-ans);
        }
        return res;
    }
};
