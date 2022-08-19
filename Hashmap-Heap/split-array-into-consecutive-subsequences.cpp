
// Link : https://leetcode.com/problems/split-array-into-consecutive-subsequences
// tricky problem so refer https://www.youtube.com/watch?v=uJ8BAQ8lASE

class Solution {
public:
bool isPossible(vector<int>& nums) {
unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
      
        unordered_map<int,int> hm;
        
        for(int n: nums){
      
            if(freq[n] == 0) continue;
            
            if(hm[n] > 0){
                hm[n]--;
                freq[n]--;
                
                hm[n+1]++;
            }
      
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
      
                hm[n+3]++;
            }
       
            else{
                return false;
            }
        }
        
        return true;
    }
};
