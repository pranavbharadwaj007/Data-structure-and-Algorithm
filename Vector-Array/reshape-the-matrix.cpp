class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(r*c!=n*m)return mat;
        vector<vector<int>>vec(r,vector<int>(c));
        for(int i=0;i<r*c;i++){
            vec[i/c][i%c]=mat[i/m][i%m];
        }
        return vec;
    }
};
