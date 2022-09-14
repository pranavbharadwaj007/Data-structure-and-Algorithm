
// Link : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

class Solution {
public:
    void helper(TreeNode* root,vector<int>&vec,int &cnt){
        if(root==NULL)return;
        vec[root->val]++;
        helper(root->left,vec,cnt);
        helper(root->right,vec,cnt);
        if(root->right==NULL && root->left==NULL){
            int odd=0;
            for(int i=1;i<=9;i++){
                if(vec[i]&1)odd++;
            }
            if(odd<=1)cnt++;
        }
        vec[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>vec(10,0);
        int cnt=0;
        helper(root,vec,cnt);
        return cnt;
    }
};
