
// Link : https://leetcode.com/problems/convert-bst-to-greater-tree/

class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return NULL;
        convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        convertBST(root->left);
        return root;
    }
};
