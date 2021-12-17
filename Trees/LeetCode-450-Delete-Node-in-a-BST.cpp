class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        TreeNode* righ=root->right;
        TreeNode* last=findl(root->left);
        last->right=righ;
        return root->left;
    }
    TreeNode* findl(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key) return helper(root);
        TreeNode* curr=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return curr;
    }
};
