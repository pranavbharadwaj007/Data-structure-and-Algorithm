
// Link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};
