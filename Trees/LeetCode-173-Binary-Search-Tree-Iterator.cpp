class BSTIterator {
private: stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    private: 
    void pushAll(TreeNode* node){
            for(;node!=NULL;st.push(node),node=node->left){
                        
           }
        }
};
