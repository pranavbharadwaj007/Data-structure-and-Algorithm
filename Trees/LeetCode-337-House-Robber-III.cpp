class Solution {
public:
    pair<int, int> rob_(TreeNode* root){
        pair<int, int> myans;
        myans.first=0;
        myans.second=0;
        if(root==NULL)return myans;
        pair<int, int> left=rob_(root->left);
        pair<int,int> right=rob_(root->right);
        
        myans.first=left.second+root->val+right.second;
        myans.second=max(left.first,left.second)+max(right.first,right.second);
        return myans;
    }
    int rob(TreeNode* root) {
        pair<int, int> res;
        res=rob_(root);
        return max(res.first,res.second);
    }
};
