class Solution {
public:
    bool isv(TreeNode* root,long maxi,long mini){
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini) return false;
        return (isv(root->left,root->val,mini) && isv(root->right,maxi,root->val));
    }
    bool isValidBST(TreeNode* root) {
        return isv(root,LONG_MAX,LONG_MIN);
    }
};
