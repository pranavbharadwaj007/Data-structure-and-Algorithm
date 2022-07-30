class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> fre2(26,0);
        for (auto word: words2){
            vector<int> temp(26,0);
            for (auto ch:word)
                temp[ch-'a']++;
            for (int i=0;i<26;i++){
                fre2[i] = max(fre2[i],temp[i]);
            }
        }
        vector<string> ans;
        for (auto word:words1){
            vector<int> fre1(26,0);
            for (auto ch:word)
                fre1[ch-'a']++;
            bool flag = true;
            for (int i =0;i<26;i++){
                if (fre1[i]<fre2[i]){
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(word);
        }
        return ans;
    }
};
