class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        map<char,int>mp1,mp2;
        for(auto x:s){
            freq1[x-'a']++;
           
        }
        for(auto it:t){
        freq2[it-'a']++;
        }
        int cnt=0;
        for(auto it:s){
            if(freq2[it-'a']<=0){
              
                cnt++;
            }else{
              freq2[it-'a']--;
            }
        }
        for(auto it:t){
            if(freq1[it-'a']<=0){
               
               
                cnt++;
            }else{
               freq1[it-'a']--;
            }
        }
        return cnt;
    }
};
