
// Link : https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
private:
    int mod = 1e9 + 7;
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size(), res = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++)
        {
            res += mp[target - arr[i]];
            res %= mod;
            
            for(int j = 0; j < i; j++)
            {
                mp[arr[i] + arr[j]]++;
            }
        }
        

        return res;
    }
};
