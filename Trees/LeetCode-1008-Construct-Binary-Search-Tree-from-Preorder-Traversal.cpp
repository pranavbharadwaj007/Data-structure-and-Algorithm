class Solution {
public:
    TreeNode* buildt(vector<int>& p,int& i,int maxi){
        if(i==p.size()|| p[i]>maxi) return NULL;
        TreeNode* root=new TreeNode(p[i++]);
        root->left=buildt(p,i,root->val);
        root->right=buildt(p,i,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        int i=0;
        return buildt(p,i,INT_MAX);
    }
};
