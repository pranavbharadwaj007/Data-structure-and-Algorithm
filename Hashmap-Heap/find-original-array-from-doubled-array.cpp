
// Link : https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        sort(ch.begin(),ch.end());
        if(ch.size()&1)return {};
        vector<int>ans;
        multiset<int>mt(ch.begin(),ch.end());
        for(int i=0;i<ch.size();i+=2){
            int elem=*mt.begin();
            mt.erase(mt.begin());
            if(mt.find(elem*2)==mt.end())return {};
            ans.push_back(elem);
            mt.erase(mt.find(elem*2));
        }
        return ans;
    }
};
