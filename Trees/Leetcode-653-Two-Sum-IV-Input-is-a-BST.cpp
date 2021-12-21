class Solution {
public:
    set<int>st;
    bool ans=false;
    void inord(TreeNode* root,int k){
        if(root==NULL)return;
            if(st.find(k-(root->val))!=st.end()){
            ans=true;
            return;
        }
        st.insert(root->val);
    
        inord(root->left,k);
        inord(root->right,k);
    }

    bool findTarget(TreeNode* root, int k) {
        inord(root,k);
        return ans;
    }
};
