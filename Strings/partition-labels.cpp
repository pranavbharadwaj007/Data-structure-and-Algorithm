// Link : https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']=i;
        }
        vector<int>vec;
        int prev=-1;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            maxi=max(maxi,freq[s[i]-'a']);
            if(maxi==i){
                vec.push_back(maxi-prev);
                prev=i;
            }
        }
        return vec;
    }
};
