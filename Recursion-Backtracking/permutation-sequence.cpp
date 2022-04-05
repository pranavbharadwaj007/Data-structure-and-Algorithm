
// Link : https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>numb;
        for(int i=1;i<n;i++){
            fact=fact*i;
            numb.push_back(i);
        }
        numb.push_back(n);
        string ans="";
        k--;
        while(true){
            ans=ans+to_string(numb[k/fact]);
            numb.erase(numb.begin()+k/fact);
            if(numb.size()==0)break;
            k=k%fact;
            fact=fact/numb.size();
        }
        return ans;
    }
};
