// Link : https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        int n=p.size();
        sort(p.begin(),p.end());
        int i=0;
        int j=n-1;
        int cnt=0;
        while(i<=j){
            if(p[i]+p[j]<=l){
                cnt++;
                i++;
                j--;
            }
            else{
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};
