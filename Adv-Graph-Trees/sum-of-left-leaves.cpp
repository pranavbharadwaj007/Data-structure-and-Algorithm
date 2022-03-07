class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool is_left=false) {
        
        if(!root){
            return 0;
        }
        
        if(!root->left && !root->right){
            if(is_left)
                return root->val;
        }
        
        return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
    }
    
};
