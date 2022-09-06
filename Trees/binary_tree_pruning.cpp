
// Link : https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        root->left = pruneTree(root->left); 
        root->right = pruneTree(root->right); 
        if (root->val == 1 || root->left != NULL || root->right != NULL) return root;
        return NULL; 
    }
};
