
// Link: https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
public:
    TreeNode* curr=NULL;
    void inorder(TreeNode* node){
        if(node==NULL)return;
        inorder(node->left);
        node->left=NULL;
        curr->right=node;
        curr=node;
        inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)return NULL;
        TreeNode* res=new TreeNode(0);
        curr=res;
        inorder(root);
        return res->right;
    }
};
