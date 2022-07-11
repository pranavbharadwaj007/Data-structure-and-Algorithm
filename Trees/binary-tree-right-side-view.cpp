
// Link : https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    void recurs(TreeNode* root,int level,vector<int>& res){
        if(root==NULL)return;
        if(res.size()==level){
            res.push_back(root->val);
        }
        recurs(root->right,level+1,res);
        recurs(root->left,level+1,res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recurs(root,0,res);
        return res;
    }
};
