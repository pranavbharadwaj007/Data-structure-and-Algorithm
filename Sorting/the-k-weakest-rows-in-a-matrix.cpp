class Solution {
public:
    
    static bool compare(pair<int,int> c1, pair<int,int> c2){
        if(c1.second != c2.second)
            return c1.second < c2.second;
        else
            return c1.first < c2.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec;
		 vector<int> ans;

        for(int i = 0; i < mat.size(); ++i){
            int soldiers = 0;
            for(int j = 0; j < mat[i].size(); ++j){
                if(mat[i][j] == 1)
                    soldiers++;
            }
            vec.push_back(make_pair(i,soldiers));
            
        }
        
        sort(vec.begin(),vec.end(),compare);
        
        for(int i = 0; i < k; ++i)
            ans.push_back(vec[i].first);
        return ans;
    }
};
