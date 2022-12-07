class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
    if(root==NULL){
            return 0;
        }
        else{
            int sum=rangeSumBST( root->left, L,  R)+rangeSumBST(root->right,  L,  R);
                if(root->val>=L && root->val<=R){
                    sum+=root->val;
                }
            return sum;
        }   
    }
};
